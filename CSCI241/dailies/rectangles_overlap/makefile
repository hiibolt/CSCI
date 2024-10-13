CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

overlap: FORCE
	$(CXX) $(CXXFLAGS) -o overlap overlap.cpp solution.cpp

clean: FORCE
	$(RM) -rf overlap *.o
	
FORCE:
