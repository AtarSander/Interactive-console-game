#include "enemy.hpp"
#include <memory>
#include <string>

void Enemy::attack(std::shared_ptr<Entity> other)
{
    int damage = getBaseDamage();
    other -> defend(damage + damage * (strength / 10));
}

void Enemy::defend(int damage)
{

}

double Enemy::checkResistance(std::string type)
{
    auto it = resistances.find(type);
    if (it != resistances.end()) { return it->second; }
    else { return 0; }
}