#include "game.hpp"
#include "player.hpp"
#include "chapter.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Invalid number of arguments. Please enter two arguments.\n";
        return 1;
    }
    std::string name = argv[1];
    int health = std::stoi(argv[2]);
    Player player(name, health);


    Game game1(player);
    Chapter chapter0(0);
    chapter0.read_from_file("seed_0.txt");
    Chapter chapter1(1);
    chapter1.read_from_file("seed_1.txt");
    Chapter chapter2(2);
    chapter2.read_from_file("seed_2.txt");
    Chapter chapter3(3);
    chapter3.read_from_file("seed_3.txt");
    Chapter chapter4(4);
    chapter4.read_from_file("seed_4.txt");
    Chapter chapter5(5);
    chapter5.read_from_file("seed_5.txt");
    Chapter chapter6(6);
    chapter6.read_from_file("seed_6.txt");
    game1.add_chapter(chapter0);
    game1.add_chapter(chapter1);
    game1.add_chapter(chapter2);
    game1.add_chapter(chapter3);
    game1.add_chapter(chapter4);
    game1.add_chapter(chapter5);
    game1.add_chapter(chapter6);
    game1.play();

    return 0;
}