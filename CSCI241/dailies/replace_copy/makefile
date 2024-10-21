CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

replace: FORCE
	$(CXX) $(CXXFLAGS) -o replace replace.cpp solution.cpp

clean: FORCE
	$(RM) -rf replace *.o
	
FORCE:
