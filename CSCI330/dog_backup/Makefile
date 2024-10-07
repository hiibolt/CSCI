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
SOURCE_DIR = src
OBJ_DIR = obj

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14

# Rule to link object code files to create executable file
dog: $(OBJ_DIR)/main.o $(OBJ_DIR)/lib.o
	$(CXX) $(CXXFLAGS) -o dog $^

# Rules to compile source code file to object code
$(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cc $(SOURCE_DIR)/lib.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/lib.o: $(SOURCE_DIR)/lib.cc $(SOURCE_DIR)/lib.h | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


$(SOURCE_DIR):
	mkdir -p $(SOURCE_DIR)
$(SOURCE_DIR)/main.cc: $(SOURCE_DIR)
	cp ./main.cc $(SOURCE_DIR)/main.cc
	rm -f $(SOURCE_DIR)/main.cc
$(SOURCE_DIR)/lib.cc: $(SOURCE_DIR)
	cp ./lib.cc $(SOURCE_DIR)/lib.cc
	rm -f $(SOURCE_DIR)/lib.cc
$(SOURCE_DIR)/lib.h: $(SOURCE_DIR)
	cp ./lib.h $(SOURCE_DIR)/lib.h
	rm -f $(SOURCE_DIR)/lib.h

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