#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "entity.hpp"
#include <string>


class Weapon : public Entity
{
    public:
    Weapon(std::string name, unsigned int durability, unsigned int base_damage,
           std::string type, double crit_chance) :
        Entity(name, durability, base_damage, 0), type(type), crit_chance(crit_chance) {};

    virtual void attack(std::shared_ptr<Entity> other) override;
    std::string getType() const;

    private:
        bool isCritical();
        std::string type;
        double crit_chance;

};
#endif