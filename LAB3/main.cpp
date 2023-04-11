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
    game1.config_chapters("seeds/config.txt");
    game1.play();

    return 0;
}