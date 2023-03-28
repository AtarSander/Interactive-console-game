#include "player.hpp"
#include <stdexcept>

std::string Player::get_name() const { return name; }

unsigned int Player::get_health() const { return health; }

void Player::set_health(int new_health)
{
    if (new_health > 0)
    {
        health = new_health;
    }
    else
    {
        throw(std::invalid_argument("Invalid input: " + std::to_string(new_health)));
    }
}