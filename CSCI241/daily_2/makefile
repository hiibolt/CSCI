#
# PROGRAM: Lab Training Exercise
# AUTHOR:  your name
#

CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14 -g 
ENTRYPOINT = insertion_sort
OUTPUT_NAME = insertion_sort

# Rule to link object code files to create executable file
$(ENTRYPOINT): main.o $(ENTRYPOINT).o
	$(CXX) $(CXXFLAGS) -o $(ENTRYPOINT) $^

# Rules to compile source code files to object code
main.o: main.cpp
$(ENTRYPOINT).o: $(ENTRYPOINT).cpp

debug:
	gdb --silent $(OUTPUT_NAME)

run:
	echo "26.49 34.33 58.79 74.27 83.34 3.33 86.19 99.51" | ./$(OUTPUT_NAME)

clean:
	rm -f *.o
	rm -f $(OUTPUT_NAME)
