#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "item.hpp"
#include <string>
#include <list>

class Player
{
    public:
        Player(std::string name_org, unsigned int hp) : name(name_org), health(hp){};
        std::string get_name() const;
        unsigned int get_health() const;
        void set_name(std::string new_name);
        void set_health(int new_health);
        void add_item(Item new_item);
        unsigned int find_useful_item(std::string type);
    private:
        std::string name;
        int health;
        std::list<Item> equipment;

};
#endif