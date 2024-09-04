#
# PROGRAM:    Bubble Sort
# PROGRAMMER: John White
# LOGON ID:   z1994244
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
OUTPUT_NAME = bubble_sort
ENTRYPOINT = bubble_sort

# Rule to link object code files to create executable file
$(ENTRYPOINT): main.o $(ENTRYPOINT).o
	$(CXX) $(CXXFLAGS) -o $(ENTRYPOINT) $^

# Rules to compile source code files to object code
main.o: main.cpp
$(ENTRYPOINT).o: $(ENTRYPOINT).cpp

debug:
	gdb --silent $(OUTPUT_NAME)

run:
	echo "frame job stop safe deport chin begin worth push faint scheme feign square course set wind orbit flavor fate net open means detail stir upset" | ./$(OUTPUT_NAME)

clean:
	rm -f *.o
	rm -f $(OUTPUT_NAME)
