CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = Squaremat.cpp
HEADERS = Squaremat.hpp

MAIN = Main.cpp
TEST = Squaremattest.cpp

OBJS = $(SRC:.cpp=.o)

main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(MAIN)

test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o test $(SRC) $(TEST)
		./test


valgrind: main
	valgrind --leak-check=full ./main
clean:
	rm -f *.o test main *.out *.exe