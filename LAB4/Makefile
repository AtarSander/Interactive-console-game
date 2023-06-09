CXX = clang++
CXX_FLAGS = -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++20

main: main.cpp game.o entityfactory.o
	$(CXX) $(CXX_FLAGS) main.cpp game.o entityfactory.o weapon.o player.o enemy.o entity.o -o main

game.o: game.cpp entityfactory.o
	$(CXX) $(CXX_FLAGS) -c game.cpp -o game.o

entityfactory.o: entityfactory.cpp entity.o enemy.o weapon.o player.o
	$(CXX) $(CXX_FLAGS) -c entityfactory.cpp -o entityfactory.o

player.o: player.cpp
	$(CXX) $(CXX_FLAGS) -c player.cpp -o player.o

weapon.o: weapon.cpp entity.o
	$(CXX) $(CXX_FLAGS) -c weapon.cpp -o weapon.o

enemy.o: enemy.cpp entity.o
	$(CXX) $(CXX_FLAGS) -c enemy.cpp -o enemy.o

entity.o: entity.cpp
	$(CXX) $(CXX_FLAGS) -c entity.cpp -o entity.o

test_entity: tests/test_entity.cpp entity.o
	$(CXX) $(CXX_FLAGS) entity.o tests/test_entity.cpp -o test_entity && ./test_entity --success

test_enemy: tests/test_enemy.cpp enemy.o entity.o
	$(CXX) $(CXX_FLAGS) entity.o enemy.o tests/test_enemy.cpp -o test_enemy && ./test_enemy --success

test_weapon: tests/test_weapon.cpp weapon.o entity.o enemy.o
	$(CXX) $(CXX_FLAGS) entity.o enemy.o weapon.o tests/test_weapon.cpp -o test_weapon && ./test_weapon --success

test: test_entity test_enemy test_weapon

clean:
	rm -f main *.o LAB4 test_*
