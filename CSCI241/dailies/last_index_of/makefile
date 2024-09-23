CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

lastndx: FORCE
	$(CXX) $(CXXFLAGS) -o lastndx lastndx.cpp solution.cpp

clean: FORCE
	$(RM) -rf lastndx *.o
	
FORCE:
