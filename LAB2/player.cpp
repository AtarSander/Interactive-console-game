#include "player.hpp"
#include <stdexcept>

std::string Player::get_name() const { return _name; }

unsigned int Player::get_health() const { return _health; }

void Player::set_health(unsigned int new_health)
{
    if (new_health > 0)
    {
        _health = new_health;
    }
    else
    {
        throw(std::invalid_argument("Invalid input: " + new_health));
    }
}