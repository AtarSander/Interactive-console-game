#include "weapon.hpp"
#include <random>

void Weapon::attack(std::shared_ptr<Entity> other)
{
    int damage = getBaseDamage();
    if (isCritical()) { damage = damage * damage; }
    other -> defend(damage);
    setHealth(getHealth() - 1);
}

bool Weapon::isCritical()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double random_value = dis(gen);
    if (random_value <= crit_chance){ return 1; }
    return 0;
}

std::string Weapon::getType() const { return type; }