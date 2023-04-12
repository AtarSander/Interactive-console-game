#include "player.hpp"
#include "item.hpp"
#include <stdexcept>
#include <list>
#include <algorithm>

std::string Player::get_name() const { return name; }

unsigned int Player::get_health() const { return health; }

void Player::set_name(std::string new_name) { name = new_name;}

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

void Player::add_item(Item new_item){  equipment.push_back(new_item);  }

std::list<Item> Player::get_equipment() const { return equipment; }

unsigned int Player::find_useful_item(std::string type)
{
    auto it = std::find_if(equipment.begin(), equipment.end(), [&](const Item& item)
    {
        return item.get_type() == type;
    });
    if (it != equipment.end())
    {
        --(*it);
        if ((*it).check_uses())
        {
            equipment.erase(it);
        }
        return 0;
    }
    return 1;
}