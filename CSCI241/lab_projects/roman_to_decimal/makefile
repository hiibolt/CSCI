CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

rtod: FORCE
	$(CXX) $(CXXFLAGS) -o rtod rtod.cpp solution.cpp

clean: FORCE
	$(RM) -rf rtod *.o
	
FORCE:
