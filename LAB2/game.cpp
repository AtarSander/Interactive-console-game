#include "game.hpp"
#include "chapter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Game::play()
{
    bool exception_occurred = false;
    while (current_seed != 999)
    {
        std::string option;


        if(!exception_occurred)
        {
            std::cout << _map_of_chapters[current_seed].get_story() << std::endl;
        }

        try
        {
            option = this -> input_option();
            current_seed = _map_of_chapters[current_seed].outcome(option);
            if (current_seed % 5 == 0)
            {
                this -> change_player_state();
            }
            exception_occurred = false;
        }
        catch(std::exception& e)
        {
            this -> wrong_input();
            exception_occurred = true;
        }

    }
}

unsigned int Game::get_chapter_count(){ return _map_of_chapters.size(); }

void Game::set_current_seed(unsigned int new_seed) { current_seed = new_seed; }

std::string Game::input_option()
{
    std::string option;
    std::cout << "> ";
    std::getline(std::cin, option);
    return option;
}

void Game::wrong_input() const
{
    std::cout << "I didn't quite catch that. Could you repeat?" << std::endl;
}

void Game::change_player_state()
{
    std::srand(std::time(nullptr));
    int random_num = std::rand() % 10 + 1;
    try
    {
        _player.set_health(_player.get_health() - random_num);
        this -> player_damage(random_num);
    }
    catch(const std::exception& e)
    {
        current_seed = 999;
    }
}

void Game::player_damage(int value)
{
    std::cout << _player.get_name() << " took " << value << " damage.\n";
    std::cout << "Current health is " << _player.get_health() << " points.\n";
}

void Game::add_chapter(Chapter next_chapter)
{
    unsigned int seed;
    seed = next_chapter.get_seed();
    _map_of_chapters[seed] = next_chapter;
}