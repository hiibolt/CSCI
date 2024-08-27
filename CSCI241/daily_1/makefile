#
# PROGRAM: Lab Training Exercise
# AUTHOR:  your name
#

CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14 -g 
OUTPUT_NAME = selection_sort

# Rule to link object code files to create executable file
selection_sort: main.o selection_sort.o
	$(CXX) $(CXXFLAGS) -o selection_sort $^

# Rules to compile source code files to object code
main.o: main.cpp
selection_sort.o: selection_sort.cpp

debug:
	gdb --silent $(OUTPUT_NAME)

run:
	echo "64 25 12 22 11" | ./$(OUTPUT_NAME)

clean:
	rm -f *.o
	rm -f $(OUTPUT_NAME)
