#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "entity.hpp"

class Weapon : public Entity {
public:
    Weapon(std::string name, unsigned int durability, unsigned int base_damage) :
        Entity(name, durability, base_damage, 0) {}

    virtual void attack(std::shared_ptr<Entity> other) override;
    virtual void defend(unsigned int damage) override;
};
#endif