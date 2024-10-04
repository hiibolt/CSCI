CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

inside: FORCE
	$(CXX) $(CXXFLAGS) -o inside inside.cpp solution.cpp

clean: FORCE
	$(RM) -rf inside *.o
	
FORCE:

run:
	./inside