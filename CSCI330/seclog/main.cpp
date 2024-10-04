/***************************************************************
CSCI 330         John White     Fall 2024

Programmer: z19942444

Section: 330-0001

Date Due: Saturday, November 5th

Purpose: Create a secret logging program
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/


#include <iostream>
#include <unistd.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <cstring>
#include <errno.h>


/**
 * @brief The program state
 */
struct State {
    char *file;
    char *message;
    bool clear;
};


/**
 * @brief Command line argument parser (CLAP)
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @return The program state
 */
State clap ( int argc, char *argv[] ) {
    State state = { NULL, NULL, false };


    // Check for optional arguments
    int opt = getopt(argc, argv, "c");
    while ( opt != -1 ) {
        switch(opt)  
        {  
            case 'c':  
                state.clear = true;
                break;
            case '?':  
                printf("Error: Recieved unknown option '-%c'\n", optopt); 
                exit(1);
        }  

        opt = getopt(argc, argv, ":if:lrx");
    }

    // Extract any remaining arguments
    for ( int i = optind; i < argc; i++ ) {
        if ( state.file == NULL ) {
            state.file = argv[i];
        } else if ( state.message == NULL ) {
            state.message = argv[i];
        } else {
            printf("Error: Unexpected argument '%s'\n", argv[i]);
            exit(1);
        }
    }
    
    // Return our program state
    return state;
}

/**
 * @brief Checks if a file exists
 * 
 * @param file The file to check
 * 
 * @return True if the file exists, false otherwise
 */
bool file_exists ( char *file ) {
    // Open the file with no permissions
    int fd = open ( file, O_PATH );

    // Check if the file exists
    if ( fd != -1 ) {
        close ( fd );

        return true;
    }

    // Return false if the file does not exist
    return false;
}

/**
 * @brief Creates a file
 * 
 * @param file The file to create
 * 
 * @return True if the file was created, false otherwise
 */
bool create_file ( char *file ) {
    // Create the file with no permissions
    int fd = open ( file, O_CREAT, 0 );

    // Check for errors
    if ( fd == -1 ) {
        return false;
    }

    // Close the file and return
    close ( fd );

    return true;
}

/**
 * @brief Loads the permissions of a file
 * 
 * @param file The file to load the permissions of
 * @param buf The buffer to store the permissions in
 * 
 * @return True if the permissions were loaded, false otherwise
 */
bool load_permissions ( char *file, char *buf ) {
    struct stat st;

    if( stat( file, &st ) == -1 ){
        return false;
    }

    buf[0] = ( st.st_mode & S_IRUSR ) ? 'r' : '-';
    buf[1] = ( st.st_mode & S_IWUSR ) ? 'w' : '-';
    buf[2] = ( st.st_mode & S_IXUSR ) ? 'x' : '-';
    buf[3] = ( st.st_mode & S_IRGRP ) ? 'r' : '-';
    buf[4] = ( st.st_mode & S_IWGRP ) ? 'w' : '-';
    buf[5] = ( st.st_mode & S_IXGRP ) ? 'x' : '-';
    buf[6] = ( st.st_mode & S_IROTH ) ? 'r' : '-';
    buf[7] = ( st.st_mode & S_IWOTH ) ? 'w' : '-';
    buf[8] = ( st.st_mode & S_IXOTH ) ? 'x' : '-';

    return true;
}

/**
 * @brief Seclog - Allows you to secretly log messages to a file
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @arg -c Clear the file before writing
 * @arg file The file to write to
 * @arg message The message to write
 * 
 * @return int The exit status, 0 if successful, 1 if not
 */
int main ( int argc, char *argv[] ) { 
    State state = clap ( argc, argv );

    // If the message is missing (but not both), print an error
    if ( state.message == NULL && state.file != NULL ) {
        fprintf ( stderr, "Error: Missing message!\n" );
        exit(1);
    }

    // If both are missing, print the usage
    if ( state.file == NULL && state.message == NULL ) {
        printf ( "Usage: %s [-c] out_file message_string\n", argv[0] );
        printf ( "\twhere the message_string is appended to file out_file.\n" );
        printf ( "\tThe -c option clears the file before the message is appended\n" );
        exit(0);
    }

    // Check if the file exists, otherwise, create it
    if ( !file_exists ( state.file ) && !create_file ( state.file ) ) {
        fprintf ( stderr, "Failed to create file: %s: %s\n", state.file, strerror(errno) );
        exit(1);
    }

    char permissions[10] = "?????????";

    // Check if you're able to load the permissions, and
    //  if the file is secret enough
    if ( !load_permissions( state.file, permissions ) ) {
        fprintf ( stderr, "Failed to get permissions for \"%s\": %s\n", state.file, strerror(errno) );
        exit(1);
    } else if ( strcmp( permissions, "---------" ) != 0 ) {
        fprintf ( stderr, "\"%s\" is not secret enough! Current permissions: %s\n", state.file, permissions );
        exit(1);
    }

    // Set the write permissions
    if ( chmod ( state.file, S_IWUSR ) == -1 ) {
        fprintf ( stderr, "Failed to set write permissions for \"%s\": %s\n", state.file, strerror(errno) );
        exit(1);
    }

    // Open the file for writing
    int fd = open ( state.file, ( state.clear ? O_TRUNC : O_APPEND ) | O_WRONLY );

    // Check for errors
    if ( fd == -1 ) {
        fprintf ( stderr, "Failed to open file '%s': %s\n", state.file, strerror(errno) );
        exit(1);
    }

    // Write the message to the file
    if ( write ( fd, state.message, strlen(state.message) ) == -1 ) {
        fprintf ( stderr, "Failed to write to file '%s': %s\n", state.file, strerror(errno) );
        exit(1);
    }

    // Write an endline to the file
    if ( write ( fd, "\n", 1 ) == -1 ) {
        fprintf ( stderr, "Failed to write to file '%s': %s\n", state.file, strerror(errno) );
        exit(1);
    }

    // Close the file
    if ( close ( fd ) == -1 ) {
        fprintf ( stderr, "Failed to close file '%s': %s\n", state.file, strerror(errno) );
        exit(1);
    }

    // Remove write permissions
    if ( chmod ( state.file, 0 ) == -1 ) {
        fprintf ( stderr, "Failed to remove write permissions for \"%s\": %s\n", state.file, strerror(errno) );
        exit(1);
    }

    return 0; 
} 