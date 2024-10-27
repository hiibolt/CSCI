# ***************************************************************
#                            Makefile
#
#
# CSCI 330         John White     Fall 2024
#
# Programmer: z19942444
#
# Section: 330-0001
#
# Date Due: Saturday, September 28rst
#
# Purpose: Emulate the UNIX `dog` command at a rudimentary level
# ***************************************************************
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
TESTS_DIR = tests

# Variables
OUTPUT = pipes

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14

# Rule to link object code files to create executable file
all: $(OBJ_DIR) $(SOURCE_DIR) $(OUTPUT)

$(OUTPUT): $(OBJ_DIR)/main.o $(OBJ_DIR)/lib.o
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $^

# Rules to compile source code file to object code
$(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cc $(SOURCE_DIR)/lib.h
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/main.cc -o $@

$(OBJ_DIR)/lib.o: $(SOURCE_DIR)/lib.cc $(SOURCE_DIR)/lib.h
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/lib.cc -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SOURCE_DIR):
	mkdir -p $(SOURCE_DIR)
	cp ./main.cc $(SOURCE_DIR)/main.cc || true
	rm -f ./main.cc
	cp ./lib.cc $(SOURCE_DIR)/lib.cc || true
	rm -f ./lib.cc || true
	cp ./lib.h $(SOURCE_DIR)/lib.h || true
	rm -f ./lib.h || true

# Phony target to remove object code and executable files
clean:
	rm -f dog *.o

run:
	./pipes

test: $(TESTS_DIR)
	echo "todo!();"
$(TESTS_DIR):
	mkdir -p $(TESTS_DIR)
	echo "todo!();"
