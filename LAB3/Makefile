CXX = clang++
CXX_FLAGS =  -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++20

main: main.cpp game.o chapter.o player.o
	$(CXX) $(CXX_FLAGS) main.cpp game.o chapter.o item.o player.o -o main

game.o: chapter.o player.o game.cpp
	$(CXX) $(CXX_FLAGS) -c game.cpp -o game.o

chapter.o: chapter.cpp
	$(CXX) $(CXX_FLAGS) -c chapter.cpp -o chapter.o

player.o: player.cpp item.o
	$(CXX) $(CXX_FLAGS) -c player.cpp -o player.o

item.o: item.cpp
	$(CXX) $(CXX_FLAGS) -c item.cpp -o item.o

test_player: player.o test/test_player.cpp item.o
	$(CXX) $(CXX_FLAGS) player.o item.o test/test_player.cpp -o test_player && ./test_player --success

test_chapter: chapter.o test/test_chapter.cpp
	$(CXX) $(CXX_FLAGS) chapter.o test/test_chapter.cpp -o test_chapter && ./test_chapter --success

test_game: chapter.o player.o game.o test/test_game.cpp
	$(CXX) $(CXX_FLAGS) game.o chapter.o player.o item.o test/test_game.cpp -o test_game && ./test_game --success

test_item: item.o test/test_item.cpp
	$(CXX) $(CXX_FLAGS) item.o test/test_item.cpp -o test_item && ./test_item --success

tests: test_item test_player test_chapter test_game

clean:
	rm -f main *.o test_player test_game test_chapter LAB*
