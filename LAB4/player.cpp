#include "player.hpp"
#include <memory>
#include <map>
#include <string>

void Player::attack(std::shared_ptr<Entity> other)
    {
        current_weapon -> attack(other);
    };

void Player::addWeapon(std::shared_ptr<Entity> weapon)
    {
        current_weapon = std::move(weapon);
    };
