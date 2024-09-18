CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = /bin/rm
OUTPUT = pb

build: FORCE
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) main.cpp PiggyBank.cpp 

clean: FORCE
	$(RM) -rf stats *.o
	
FORCE:

run:
	./$(OUTPUT)