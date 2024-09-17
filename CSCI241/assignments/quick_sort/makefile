#
# PROGRAM:    Quicksort
# PROGRAMMER: John White
# LOGON ID:   z1994244
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
OUTPUT_NAME = quicksort

# Rule to link object code files to create executable file
quicksort: main.o quicksort.o
	$(CXX) $(CXXFLAGS) -o quicksort $^

# Rules to compile source code files to object code
main.o: main.cpp
quicksort.o: quicksort.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f *.o quicksort

run:
	echo "31 81 22 48 13 67 93 14 45 58 79 72" | ./$(OUTPUT_NAME)
