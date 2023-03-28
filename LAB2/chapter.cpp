#include "chapter.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

std::string Chapter::get_story() const { return story; }

unsigned int Chapter::get_seed() const { return seed; }

unsigned int Chapter::outcome(std::string response)
{
    auto it = list_of_options.find(response);
    if (it != list_of_options.end()) { return it->second; }
    else {throw std::invalid_argument("Wrong input: " + response); }

}

void Chapter::read_from_file(std::string filename)
{
    std::ifstream file(filename);
    std::string line;
    std::string line2;

    if (!file.is_open())
    {
        throw std::runtime_error("Couldn't open the file.");
    }

    std::getline(file, line);
    seed = std::stoi(line);

    while (std::getline(file, line))
    {
        if (line.find("RESPONSE") != std::string::npos)
        {
            break;
        }
        story += line + "\n";
    }

    while (true)
    {
        std::getline(file, line);
        if (line.find("END") != std::string::npos)
        {
            break;
        }
        std::getline(file, line2);
        std::string text;
        int number;
        text = line;
        number = std::stoi(line2);
        list_of_options[text] = number;
        std::cout<<text<<std::endl;
        std::cout<<list_of_options[text]<<std::endl;
    }
    file.close();

}
void Chapter::get_options()
{
    std::cout << list_of_options["light the torch"];
}