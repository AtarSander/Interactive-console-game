#include "game.hpp"
#include "chapter.hpp"
#include "player.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>

void Game::play()
{
    bool exception_occurred = false;
    auto start = std::chrono::steady_clock::now();
    while (current_seed != 999)
    {
        std::string option;
        if(current_seed == 1001)
        {
            auto end = std::chrono::steady_clock::now();
            auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            game_time = elapsed_seconds.count();
            this -> save_game("save.txt");
            exit(0);
        }

        if(current_seed == 1002)
        {
            this -> load_game("save.txt");
        }

        if(!exception_occurred)
        {
            std::cout << map_of_chapters[current_seed].get_story() << std::endl;
        }

        try
        {
            exception_occurred = false;
            option = this -> input_option();
            previous_seed = current_seed;
            current_seed = map_of_chapters[current_seed].outcome(option);
            if (current_seed % 5 == 0)
            {
                if (current_seed % 10 == 0)
                {
                    if(player.find_useful_item("damage") == 0)
                    {
                        current_seed +=7;
                    }
                    else
                    {
                        this -> change_player_state();
                    }

                }
                else
                {
                this -> change_player_state();
                }
            }
            if (current_seed % 11 == 0)
            {
                Item item_1("Powerful scroll", "damage", 1);
                player.add_item(item_1);
            }
        }
        catch(std::invalid_argument& e)
        {
            this -> wrong_input();
            exception_occurred = true;
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    unsigned int seconds = elapsed_seconds.count() + game_time;
    unsigned int hours = seconds / 3600;
    unsigned int minutes = (seconds % 3600) / 60;
    std::cout << "\n\nGAME OVER\n\n";
    std::cout << "Playtime: " << hours << "h " << minutes << "min " << seconds << "seconds" << std::endl;
    exit(0);
}

unsigned int Game::get_chapter_count(){ return map_of_chapters.size(); }

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
        player.set_health(player.get_health() - random_num);
        this -> player_damage(random_num);
    }
    catch(const std::exception& e)
    {
        current_seed = 998;
    }
}

void Game::player_damage(int value)
{
    std::cout << player.get_name() << " took " << value << " damage.\n";
    std::cout << "Current health is " << player.get_health() << " points.\n";
}

void Game::add_chapter(Chapter next_chapter)
{
    unsigned int seed;
    seed = next_chapter.get_seed();
    map_of_chapters[seed] = next_chapter;
}

Chapter Game::get_chapter(unsigned int seed)
{
    auto it = map_of_chapters.find(seed);
    if (it != map_of_chapters.end()) { return it->second; }
    else {throw std::invalid_argument("Wrong input: " +  std::to_string(seed)); }
}

Player Game::get_player() const{ return player; }

unsigned int Game::get_current_seed() { return current_seed; }

void Game::config_chapters(std::string config_file)
{
    std::ifstream file(config_file);
    std::string line;
    unsigned int i=0;

    if (!file.is_open())
    {
        throw std::runtime_error("Couldn't open the file.");
    }

    std::getline(file, line);
    chap_count = std::stoi(line);
    Chapter* chapters = new Chapter[chap_count];


    while (std::getline(file, line))
    {
        if (line.find("END") != std::string::npos)
        {
            break;
        }
        std::string text;
        text = line;
        char last_char =text[text.size() - 1];
        if (last_char == '\r')
        {
            text = text.substr(0, text.length() - 1); //deleting \r for windows files
        }
        chapters[i].read_from_file(text);
        this -> add_chapter(chapters[i]);
        i++;
    }
    delete[] chapters;
    file.close();
}

void Game::save_game(std::string save_file)
{
    std::ofstream filename(save_file);
    if(filename.is_open())
    {
        filename << previous_seed << "\n";
        filename << player.get_name() << "\n";
        filename << player.get_health() << "\n";
        filename << game_time << "\n";
    }
    else
    {
        throw std::runtime_error("Couldn't open the file.");
    }
}

void Game::load_game(std::string save_file)
{
    std::ifstream file(save_file);
    std::string line;

    std::getline(file, line);
    current_seed = std::stoi(line);
    previous_seed = current_seed;

    std::getline(file, line);
    player.set_name(line);

    std::getline(file, line);
    player.set_health(std::stoi(line));

    std::getline(file, line);
    game_time = std::stoi(line);
}
