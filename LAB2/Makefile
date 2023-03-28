CXX = clang++
CXX_FLAGS =  -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++20

main: main.cpp game.o chapter.o player.o
	$(CXX) $(CXX_FLAGS) main.cpp game.o chapter.o player.o -o main

game.o: chapter.o player.o game.cpp
	$(CXX) $(CXX_FLAGS) -c game.cpp -o game.o

chapter.o: chapter.cpp
	$(CXX) $(CXX_FLAGS) -c chapter.cpp -o chapter.o

player.o: player.cpp
	$(CXX) $(CXX_FLAGS) -c player.cpp -o player.o

clean:
	rm -f main *.o
