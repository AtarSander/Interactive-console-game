#include "entity.hpp"
#include <memory>
#include <string>



void Entity::attack(std::shared_ptr<Entity> other)
{
    other -> defend(base_damage);
}

void Entity::defend(int damage)
{
    if (base_armor < 0)
    { base_armor = 0; }
    base_armor = base_armor - (damage * 0.2);
    damage = damage * 0.8;
    health = health - damage;

}

bool Entity::exists() const
{
    return health > 0;
}

std::string Entity::getName() const { return name;}

int Entity::getHealth() const { return health;}

int Entity::getBaseDamage() const { return base_damage;}

int Entity::getBaseArmor() const { return base_armor;}
