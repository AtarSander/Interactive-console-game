#include "chapter.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string Chapter::get_story() const { return _story; }

unsigned int Chapter::get_seed() const { return _seed; }

unsigned int Chapter::outcome(std::string response)
{
    auto it = _list_of_options.find(response);
    if (it != _list_of_options.end()) { return it->second; }
    else { throw std::invalid_argument("Wrong input: " + response); }

}

void Chapter::read_from_file(std::string filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Couldn't open the file.");
    }


    file >> _seed;
    std::string line;
    while (std::getline(file, line))
    {
        if (line == "RESPONSE")
        {
            break;
        }
        _story += line + "\n";
    }

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            break;
        }
        std::istringstream iss(line);
        std::string option_text;
        int option_number;
        iss >> option_text >> option_number;
        _list_of_options[option_text] = option_number;
    }
    file.close();

}