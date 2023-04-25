#include "entity.hpp"
#include <memory>
#include <string>



void Entity::attack(std::shared_ptr<Entity> other)
{
    other -> defend(base_damage);
}

void Entity::defend(int damage)
{
    if (base_armor > 0)
    {
        base_armor = base_armor - (damage * 0.2);
        damage = damage * 0.8;
    }
    health = health - damage;

}

bool Entity::exists() const
{
    return health > 0;
}

void Entity::setHealth(int new_health)
{
    health = new_health;
}

void Entity::setArmor(int new_armor)
{
    base_armor = new_armor;
}

void Entity::transferParameter(std::string data){ parameter = data; }

std::string Entity::getName() const { return name;}

std::string Entity::getParameter() const { return parameter;}

int Entity::getHealth() const { return health;}

int Entity::getBaseDamage() const { return base_damage;}

int Entity::getBaseArmor() const { return base_armor;}