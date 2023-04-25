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

class EntityFactory {
public:
    std::unique_ptr<Entity> createEntity(EntityType type, std::string name,
                                         int health, int base_damage,
                                         int base_armor, std::string weapon_type,
                                         std::map<std::string, double> enemy_resistances, double crit_chance);

private:
    std::unique_ptr<Entity> createEnemy(std::string name, int health,
                                        int base_damage, int base_armor,
                                        std::map<std::string, double> enemy_resistances);
    std::unique_ptr<Entity> createWeapon(std::string name, int durability, int base_damage,
                                         std::string type, double crit_chance);
    std::unique_ptr<Entity> createPlayer(std::string name, int health, int base_damage,
                                         int base_armor);
};
#endif