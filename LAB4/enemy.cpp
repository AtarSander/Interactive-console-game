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
    double resistance = checkResistance(getParameter());
    damage = damage * (1 - resistance);
    if (getBaseArmor() > 0)
    {
        setArmor(getBaseArmor() - (damage * 0.2));
        damage = damage * 0.8;
    }
    setHealth(getHealth() - damage);
}

double Enemy::checkResistance(std::string type)
{
    auto it = resistances.find(type);
    if (it != resistances.end()) { return it->second; }
    else { return 0; }
}

void Enemy::addResistance(std::string name, double value)
{
    resistances[name] = value;
}