#include "chapter.hpp"
#include <string>

std::string Chapter::get_story() const { return _story; }

unsigned int Chapter::get_seed() const { return _seed; }

unsigned int Chapter::outcome(std::string response)
{
    auto it = _list_of_options.find(response);
    if (it != _list_of_options.end()) return it->second;
    else
    {
        return 0;
    }

}