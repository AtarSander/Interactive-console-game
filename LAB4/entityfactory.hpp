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
    Weapon,
    Player
};

class EntityFactory
{
public:
    std::shared_ptr<Entity> createEntity(EntityType type, std::string name,
                                         int health, int base_damage,
                                         int base_armor, std::map<std::string, double> enemy_resistances = {},
                                         std::string weapon_type ="",
                                         double crit_chance=0);

private:
    std::shared_ptr<Entity> createEnemy(std::string name, int health,
                                        int base_damage, int base_armor,
                                        std::map<std::string, double> enemy_resistances);
    std::shared_ptr<Entity> createWeapon(std::string name, int durability, int base_damage,
                                         std::string type, double crit_chance);
    std::shared_ptr<Entity> createPlayer(std::string name, int health, int base_damage,
                                         int base_armor);
};
#endif