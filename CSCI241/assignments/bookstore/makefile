#
# PROGRAM:    Assignment 9
# PROGRAMMER: John White
# LOGON ID:   z1994244
# DATE DUE:   ASAP
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
        
# Rule to link object code files to create executable file
book_store: main.o book.o book_store.o
	$(CXX) $(CXXFLAGS) -o book_store $^

# Rules to compile source code file to object code
main.o: main.cpp book_store.h
book.o: book.cpp book.h
book_store.o: book_store.cpp book_store.h

# Phony target to remove object code and executable files
clean:
	rm -f book_store *.o

run:
	./book_store