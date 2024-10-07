#***************************************************************
#                            Makefile
#
#
#CSCI 330         John White     Fall 2024
#
#Programmer: z19942444
#
#Section: 330-0001
#
#Date Due: Saturday, September 28rst
#
#Purpose: Emulate the UNIX `cat` command at a rudimentary level
#***************************************************************
#
#
#
#    /ᐠ - ˕ -マ
#
#    @hiibolt on GitHub
#
#
#

# Directories

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14

# Rule to link object code files to create executable file
dog: main.o lib.o
	$(CXX) $(CXXFLAGS) -o dog $^

# Rules to compile source code file to object code
main.o: main.cc lib.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib.o: lib.cc lib.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target to remove object code and executable files
clean:
	rm -f dog *.o

build:
	make dog

run:
	./dog

test:
	./dog file1 | diff - tests/t1.txt
	./dog -n 5 file1 | diff - tests/t2.txt
	./dog -n 5 -c 1 file1 | diff - tests/t3.txt
	./dog -n 5 -h file1 | diff - tests/t4.txt
	./dog -n 5 -b file1 | diff - tests/t5.txt