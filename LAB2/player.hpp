#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player
{
    public:
        Player(std::string name_org, unsigned int hp) : name(name_org), health(hp){};
        std::string get_name() const;
        unsigned int get_health() const;
        void set_health(int new_health);
    private:
        std::string name;
        int health;
};
#endif