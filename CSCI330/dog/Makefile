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
TESTS_DIR = tests

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14

# Rule to link object code files to create executable file
all: $(OBJ_DIR) $(SOURCE_DIR)
	make dog
	printf "\n\n\`dog\` compiled successfully!\n"
dog: $(OBJ_DIR)/main.o $(OBJ_DIR)/lib.o
	$(CXX) $(CXXFLAGS) -o dog $^
	printf "\n\n\`dog\` compiled successfully!\n"

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

build:
	make dog

run:
	./dog

test: $(TESTS_DIR)
	./dog tests/testfile | diff - tests/t1.txt
	./dog -n 5 tests/testfile | diff - tests/t2.txt
	./dog -n 5 -c 1 tests/testfile | diff - tests/t3.txt
	./dog -n 5 -h tests/testfile | diff - tests/t4.txt
	./dog -n 5 -b tests/testfile | diff - tests/t5.txt

$(TESTS_DIR):
	mkdir -p $(TESTS_DIR)
	printf "Hello World" > $(TESTS_DIR)/t1.txt
	printf "Hello" > $(TESTS_DIR)/t2.txt
	printf "Ifmmp" > $(TESTS_DIR)/t3.txt
	printf "48656c6c6f" > $(TESTS_DIR)/t4.txt
	printf "0100100001100101011011000110110001101111" > $(TESTS_DIR)/t5.txt
	printf "Hello World" > tests/testfile