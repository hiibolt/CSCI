#
# PROGRAM:    Assignment 10
# PROGRAMMER: John White 
# LOGON ID:   z1994244
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
        
# Rule to link object code files to create executable file
complex: main.o complex.o
	$(CXX) $(CXXFLAGS) -o complex $^

# Rules to compile source code file to object code
main.o: main.cpp complex.h
complex.o: complex.cpp complex.h
   
# Pseudo-target to remove object code and executable files
clean:
	rm -f complex *.o
