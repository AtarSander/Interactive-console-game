#ifndef ENTITYFACTORY_HPP
#define ENTITYFACTORY_HPP
#include "entity.hpp"
#include "enemy.hpp"
#include "weapon.hpp"
#include <memory>
#include <string>

enum class EntityType
{
    Enemy,
    Weapon
};

class EntityFactory {
public:
    std::unique_ptr<Entity> createEntity(EntityType type, std::string name,
                                         int health, int base_damage,
                                         int base_armor, std::string weapon_type,
                                         std::map<std::string, double> enemy_resistances);

private:
    std::unique_ptr<Entity> createEnemy(std::string name, unsigned int health,
                                        unsigned int base_damage, unsigned int base_armor,
                                        std::map<std::string, double> enemy_resistances);
    std::unique_ptr<Entity> createWeapon(std::string name, unsigned int base_damage, std::string type);
};
#endif