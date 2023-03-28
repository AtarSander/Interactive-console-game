#include "game.hpp"
#include <iostream>

void Game::play()
{
    bool exception_occurred = false;
    while (current_seed != 999)
    {
        Chapter current_chapter = _map_of_chapters[current_seed];
        std::string option;


        if(!exception_occurred)
        {
            std::cout << current_chapter.get_story() << std::endl;
        }

        try
        {
            option = this -> input_option();
            current_seed = current_chapter.outcome(option);
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

std::string input_option()
{
    std::string option;
    std::cout << "> ";
    std::cin >> option;
    return option;
}

void Game::wrong_input()
{
    std::cout << "I didn't quite catch that. Could you repeat?" << std::endl;
}