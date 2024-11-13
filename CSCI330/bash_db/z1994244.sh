#!/nix/store/4bj2kxdm1462fzcc2i2s4dn33g2angcc-bash-5.2p32/bin/bash

# [ Helper Functions ]
#######################################
# Err helper print function, which also
#  exits the script if the error type is
#  FATAL.
# Globals:
#   ERR_TYPE
# Arguments:
#   $1 - The error message to print.
# Outputs:
#   Writes the error message to stdout.
#######################################
err ( ) {
	echo "[ Error ] $1" >&2;

	if [ "$ERR_TYPE" = "FATAL" ]; then
		exit 1;
	fi
}
#######################################
# Warn helper print function.
# Arguments:
#   $1 - The warning message to print.
# Outputs:
#   Writes the warning message to stdout.
#######################################
warn ( ) {
	echo "[ Warning ] $1";
}
#######################################
# Info helper print function.
# Arguments:
#   $1 - The info message to print.
# Outputs:
#   Writes the info message to stdout.
#######################################
info ( ) {
	echo "[ Info ] $1";
}
#######################################
# Ensure that the database exists and is
#  readable and writable.
# Arguments:
#   $1 - The database filename.
# Outputs:
#   Writes an error message if the database
#    does not exist, is not readable, or is
#    not writable.
# Returns:
#   1 - If the database does not exist, is not
#        readable, or is not writable.
#######################################
ensure_database ( ) {
	if [ ! -f "$1" ]; then
		err "Database '$1' does not exist!"; 
		return 1;
	elif [ ! -w "$1" ]; then
		err "Database '$1' is not writable!";
		return 1;
	elif [ ! -r "$1" ]; then
		err "Database '$1' is not readable!";
		return 1;
	fi
}
################################
# Print a goodbye message to the
#  user.
# Outputs:
#   Writes a goodbye message to stdout.
################################
goodbye ( ) {
	HEADER="Goodbye...";
	HEADER_LEN="${#HEADER}";

	for CHAR in `echo "$HEADER" | sed -e 's/./& /g'`; do
		sleep 0.015;
		
		if [ "$CHAR" = "." ]; then
			sleep 0.065;
		fi

		printf "$CHAR";
	done

	sleep 0.2;

	printf "\n\n/ᐠ - ˕ -マ\n";
}

# [ Primary commands ]
#######################################
# Count the number of records in the
#  database.
# Globals:
#   FILENAME
# Arguments:
#   $1 - The database filename.
# Outputs:
#   Writes an error message if the number
#    of arguments is invalid, or if the
#    database does not exist or is not
#    readable. Otherwise, writes the number
#    of records in the database to stdout.
# Returns:
#   1 - If the number of arguments is invalid,
#        or if the database does not exist or
#        is not readable.
#######################################
count ( ) {
	# Verify arguments
	if [ $# -le 0 ]; then
		err "You must supply at least two arguments!"
		return 1;
	elif [ $# -gt 1 ]; then
		warn "You supplied too many arguments for 'count'!";
	fi

	# Extract the filename
	FILENAME="$1"

	# Enusure that the database exists and is readable
	ensure_database "$FILENAME" || return 1;
	
	# Count the number of records
	awk 'END { print NR-1 }' "$FILENAME";
}
#######################################
# Insert a record into the database.
# Globals:
#   FILENAME
#   MAKE
#   MODEL
#   YEAR
#   COLOR
# Arguments:
#   $1 - The database filename.
#   $2 - The make of the record.
#   $3 - The model of the record.
#   $4 - The year of the record.
#   $5 - The color of the record.
# Outputs:
#   Writes an error message if the number of
#    arguments is invalid, or if the make, model,
#    year, or color are invalid. Otherwise, writes
#    a success message to stdout.
# Returns:
#   1 - If the number of arguments is invalid, or
#        if the make, model, year, or color are invalid.
#######################################
insert ( ) {
	# Verify argument number
	if [ $# -lt 5 ]; then
		err "You must provide at least 5 arguments to insert a record!";
		return 1;
	elif [ $# -gt 5 ]; then
		warn "Recieved too many arguments for record insertion!";
	fi

	# Extract arguments
	FILENAME="$1"
	MAKE="$2"
	MODEL="$3"
	YEAR="$4"
	COLOR="$5"

	# Verify valid arguments
	if [ -z "$MAKE" ]; then
		err "Record make must be a non-zero string!";
		return 1;
	elif [ -z "$MODEL" ]; then 
		err "Record model must be a non-zero length string!";
		return 1;
	elif [ "$YEAR" -lt 1922 -o "$YEAR" -gt 2028 ]; then
		err "Record year must be between 1921 and 2029!";
		return 1;
	elif [ -z "$COLOR" ]; then
		err "Record color must be a non-zero length string!";
		return 1;
	fi

	# Create the record's string
	RECORD="$MAKE, $MODEL, $YEAR, $COLOR";

	# Check that the database exists and is writable
	ensure_database "$FILENAME" || return 1;

	# Add the record and inform the user
	echo "$RECORD" >> ./"$FILENAME" 
	info "Added record '$RECORD' to database '$FILENAME'";
}
#######################################
# Create a new database.
# Globals:
#   FILENAME
#   HEADER
# Arguments:
#   $1 - The filename of the database.
#   $2 - The header of the database. (Optional)
# Outputs:
#   Writes an error message if the number of arguments
#    is invalid, or if the database already exists. Otherwise,
#    writes a success message to stdout.
# Returns:
#   1 - If the number of arguments is invalid, or if the
#        database already exists.
#######################################
create ( ) {
	# Verify arguments
	if [ $# -eq 0 ]; then
		err "You must supply a filename to create a database!";
		return 1;
	fi	

	# Extract the filename and header
	FILENAME="$1"
	HEADER="Untitled Database"

	# If we got a header, use it instead of the default
	if [ $# -gt 1 ]; then
		HEADER="${@:2}";
	fi

	# Check if it alredy exists
	if [ -f "$FILENAME" ]; then
		err "Database file $FILENAME already exists!";
		return 1;
	fi

	# Create the database
	echo "$HEADER" > ./"$FILENAME"
	echo "[ Info ] Created database '$FILENAME' with header '$HEADER' successfully!"
}
#######################################
# Display records from the database.
# Globals:
#   FILENAME
#   DISPLAY_TYPE
#   RECORD_NUMBER
#   COUNT
#   START_NUM
#   END_NUM
# Arguments:
#   $1 - The database filename.
#   $2 - The display type. (all, single, range)
#   $3 - The record number or starting range number.
#   $4 - The ending range number. (Optional)
# Outputs:
#   Writes an error message if the number of arguments
#    is invalid, or if the database does not exist or is
#    not readable. Otherwise, writes the requested records
#    to stdout.
# Returns:
#   1 - If the number of arguments is invalid, or if the
#        database does not exist or is not readable.
#######################################
display ( ) {
	# Verify that we got a filename
	if [ $# -le 1 ]; then
		err "You must supply at least two arguments!"
		return 1;
	fi

	# Extract the filename and display type
	FILENAME="$1"
	DISPLAY_TYPE="$2"

	# Verify that the database exists and is readable
	ensure_database "$FILENAME" || return 1;

	# Appy the correct display type
	case "$DISPLAY_TYPE" in
		"all")
			# Verify arguments
			if [ $# -gt 2 ]; then
				warn "You supplied too many arguments to do an 'all' lookup!";
			fi

			# Print the entire database (including the header)
			cat "$FILENAME";
			printf "\n";
			;;
		"single")
			# Verify arguments
			if [ $# -le 2 ]; then
				err "You must provide a record number to do a 'single' lookup!";
				return 1;
			elif [ $# -gt 3 ]; then
				warn "You supplied too many arguments to do a 'single' lookup!";
			fi

			# Extract the record number and count the records in the db
			RECORD_NUMBER="$3";
			COUNT=`awk 'END { print NR-1 }' "$FILENAME"`;
			
			# Verify the count and record number are valid
			if [ $COUNT -eq 0 ]; then
				err "There are no records in database '$FILENAME'!";
				return 1;
			fi
			if [ "$RECORD_NUMBER" -gt $COUNT ] || [ "$RECORD_NUMBER" -lt 1 ]; then
				err "You must provide a record number between 1 and $COUNT (inclusively)!";
				return 1;
			fi

			# Print only the provided record
			awk "\
			BEGIN { \
				FS=\", \" \
			} \
			NR ~ ""$RECORD_NUMBER""+1 { print \$0 }" "$FILENAME";
			;;
		"range")
			# Verify arguments
			if [ $# -le 3 ]; then
				err "You must provide both a starting and ending range number!";
				return 1;
			elif [ $# -gt 4 ]; then
				warn "You supplied too many arguments to do a 'range' lookup!";
			fi

			# Extract the count and starting / ending record number
			START_NUM="$3"
			END_NUM="$4"
			COUNT=`awk 'END { print NR-1 }' "$FILENAME"`;

			# Verify that the record numbers and count are valid
			if [ $COUNT -eq 0 ]; then
				err "There are no records in database '$FILENAME'!";
				return 1;
			elif [ $COUNT -eq 1 ]; then
				err "There is only one record! Please instead use 'all' or 'single'!";
				return 1;
			fi
			if [ "$START_NUM" -gt $(($COUNT-1)) ] || [ "$START_NUM" -lt 1 ]; then
				err "The starting record must be greater than 1 and less than the last (#$COUNT)";
				return 1;
			fi
			if [ "$START_NUM" -ge "$END_NUM" ]; then
				err "The ending range number must be greater than the starting range number!";
				return 1;
			fi
			if [ "$END_NUM" -gt $COUNT ]; then
				err "The ending range number must be less than or equal to $COUNT!";
				return 1;
			fi

			# Print the range of records
			awk "\
			BEGIN { \
				FS=\", \" \
			} \
			NR ~ $START_NUM+1,NR ~$END_NUM+1 { print \$0 }" "$FILENAME";
			;;
		*)
			err "Recieved invalid display type '$DISPLAY_TYPE'!";
			return 1;
			;;
	esac
}
#######################################
# Delete records from the database.
# Globals:
#   FILENAME
#   DELETE_TYPE
#   RECORD_NUMBER
#   COUNT
#   START_NUM
#   END_NUM
# Arguments:
#   $1 - The database filename.
#   $2 - The delete type. (all, single, range)
#   $3 - The record number or starting range number.
#   $4 - The ending range number. (Optional)
# Outputs:
#   Writes an error message if the number of arguments
#    is invalid, or if the database does not exist or is
#    not readable. Otherwise, writes a success message to
#    stdout.
# Returns:
#   1 - If the number of arguments is invalid, or if the
#        database does not exist or is not readable.
#######################################
delete ( ) {
	# Verify arguments
	if [ $# -le 1 ]; then
		err "You must supply at least two arguments!"
		return 1;
	fi

	# Extract the filename and delete type
	FILENAME="$1"
	DELETE_TYPE="$2"

	# Check that the database exists and is writable
	ensure_database "$FILENAME" || return 1;

	# Apply the correct deletion type
	case "$DELETE_TYPE" in
		"all")
			# Verify arguments
			if [ $# -gt 2 ]; then
				warn "You supplied too many arguments to do an 'all' lookup!";
			fi

			# Delete all records (exempting the header)
			sed -i -e '2,$d' "$FILENAME";
			info "Success!";
			;;
		"single")
			# Verify arguments
			if [ $# -le 2 ]; then
				err "You must provide a record number to do a 'single' delete!";
				return 1;
			elif [ $# -gt 3 ]; then
				warn "You supplied too many arguments to do a 'single' delete!";
			fi

			# Extract the record number and count records
			RECORD_NUMBER="$3";
			COUNT=`awk 'END { print NR-1 }' "$FILENAME"`;
			
			# Verify that the count and record number are valid
			if [ $COUNT -eq 0 ]; then
				err "There are no records in database '$FILENAME'!";
				return 1;
			fi
			if [ "$RECORD_NUMBER" -gt $COUNT ] || [ "$RECORD_NUMBER" -lt 1 ]; then
				err "You must provide a record number between 1 and $COUNT (inclusively)!";
				return 1;
			fi

			# Delete only the provided record
			sed -i -e "$(($RECORD_NUMBER+1)) d" "$FILENAME";
			info "Success!";
			;;
		"range")
			# Verify arguments
			if [ $# -le 3 ]; then
				err "You must provide both a starting and ending range number!";
				return 1;
			elif [ $# -gt 4 ]; then
				warn "You supplied too many arguments to do a 'range' delete!";
			fi

			# Extract the count and starting / ending record number
			START_NUM="$3"
			END_NUM="$4"
			COUNT=`awk 'END { print NR-1 }' "$FILENAME"`;

			# Verify that the count and starting / ending record numbers are valid
			if [ $COUNT -eq 0 ]; then
				err "There are no records in database '$FILENAME'!";
				return 1;
			elif [ $COUNT -eq 1 ]; then
				err "There is only one record! Please use 'all' or 'single'!";
				return 1;
			fi
			if [ "$START_NUM" -gt $(($COUNT-1)) ] || [ "$START_NUM" -lt 1 ]; then
				err "The starting record must be greater than 1 and less than the last (#$COUNT)";
				return 1;
			fi
			if [ "$START_NUM" -ge "$END_NUM" ]; then
				err "The ending range number must be greater than the starting range number!";
				return 1;
			fi
			if [ "$END_NUM" -gt $COUNT ]; then
				err "The ending range number must be less than or equal to $COUNT!";
				return 1;
			fi

			# Delete the requested record range
			sed -i -e "$(($START_NUM+1)),$(($END_NUM+1)) d" "$FILENAME";
			info "Success!";
			;;
		*)
			err "Recieved invalid delete type '$DELETE_TYPE'!";
			return 1;
			;;
	esac
}

# [ Primary Logic ]
#######################################
# Handle the command provided by the user.
# Globals:
#   FILENAME
#   COMMAND
# Arguments:
#   $@ - The arguments provided by the user.
# Outputs:
#   Writes an error message if the number of arguments
#    is invalid, or if the command is invalid. Otherwise,
#    executes the command.
#######################################
handle_command ( ) {
	# Verify that we got a database filename and command
	if [ $# -le 1 ]; then
		err "You must provide at least two arguments!";
		return 1;
	fi

	# Extract the filename and command
	FILENAME="$1";
	COMMAND="$2";

	# Handle the command
	case "$COMMAND" in
		"create")
			create "$FILENAME" "${@:3}"
			;;
		"insert")
			insert "$FILENAME" "${@:3}"
			;;
		"display")
			display "$FILENAME" "${@:3}"
			;;	
		"delete")
			delete "$FILENAME" "${@:3}"
			;;
		"count")
			count "$FILENAME" "${@:3}"
			;;
		*)
			err "Recieved invalid command '$COMMAND'!";
			return 1;
			;;
	esac
}

# [ Main ]
# Check if we are in REPL mode
if [ $# -eq 0 ]; then
	echo "You have entered REPL mode! Enter ':q' to quit.";
	while [ true ]; do
		# Prompt the user
		printf '> ';
		IFS= read -r COMMAND;

		# Treat the arguments as our own
		eval "set -- $COMMAND"

		# Check if it was a quit command
		if [ "$1" = ":q" ]; then
			goodbye;

			break;
		fi

		# Handle the command
		handle_command "$@";
	done
else
	# Since we are in one-shot mode, we will treat the 
	#  arguments as our own and enable fatal errors.
	ERR_TYPE="FATAL"
	handle_command "$@";
fi
