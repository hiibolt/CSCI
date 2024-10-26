CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

windback: FORCE
	$(CXX) $(CXXFLAGS) -o windback windback.cpp solution.cpp

clean: FORCE
	$(RM) -rf windback *.o
	
FORCE:

