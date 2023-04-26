#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "entity.hpp"
#include <memory>
#include <map>
#include <string>

class Enemy : public Entity
{
    public:
        Enemy(std::string name, unsigned int health,
              unsigned int base_damage, unsigned int base_armor,
              std::map<std::string, double> resistances) :
        Entity(name, health, base_damage, base_armor), resistances(resistances) {}

        virtual void attack(std::shared_ptr<Entity> other) override;
        virtual void defend(int damage) override;
        double checkResistance(std::string type);
        void addResistance(std::string name, double value);

    private:
        unsigned int strength=0;
        std::map<std::string, double> resistances={};

};

#endif