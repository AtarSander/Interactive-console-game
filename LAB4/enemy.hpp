#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "entity.hpp"
#include <string>
#include <memory>

class Enemy : public Entity
{
    public:
        Enemy(std::string name, unsigned int health, unsigned int base_damage, unsigned int base_armor) :
        Entity(name, health, base_damage, base_armor) {}

    virtual void attack(std::shared_ptr<Entity> other) override;
    virtual void defend(unsigned int damage) override;
};

#endif