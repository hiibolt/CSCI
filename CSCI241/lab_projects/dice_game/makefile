CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

dice: FORCE
	$(CXX) $(CXXFLAGS) -o dice main.cpp solution.cpp

clean: FORCE
	$(RM) -rf heapsort *.o
	
FORCE:
