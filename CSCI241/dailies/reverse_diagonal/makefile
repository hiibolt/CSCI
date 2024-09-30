CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
RM = rm

diagonal: FORCE
	$(CXX) $(CXXFLAGS) -o diagonal diagonal.cpp solution.cpp

clean: FORCE
	$(RM) -rf diagonal *.o
	
FORCE:
