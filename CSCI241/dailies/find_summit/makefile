CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

summit: FORCE
	$(CXX) $(CXXFLAGS) -o summit summit.cpp solution.cpp

clean: FORCE
	$(RM) -rf summit *.o
	
FORCE:
