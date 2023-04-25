#include "entity.hpp"
#include "enemy.hpp"
#include "weapon.hpp"
#include "player.hpp"
#include "entityfactory.hpp"
#include <memory>
#include <string>
#include <stdexcept>

std::shared_ptr<Entity> EntityFactory::createEntity(EntityType type, std::string name,
                                         int health, int base_damage,
                                         int base_armor, std::map<std::string, double> enemy_resistances,
                                         std::string weapon_type,
                                         double crit_chance)
{
  switch (type)
  {
    case EntityType::Enemy:
      return createEnemy(name, health, base_damage, base_armor, enemy_resistances);
    case EntityType::Weapon:
      return createWeapon(name, health, base_damage, weapon_type, crit_chance);
    case EntityType::Player:
      return createPlayer(name, health, base_damage, base_armor);
    default:
      throw std::invalid_argument("Invalid entity type");
  }
}

std::shared_ptr<Entity> EntityFactory::createEnemy(std::string name, int health, int base_damage,
                                                   int base_armor, std::map<std::string,
                                                   double> enemy_resistances)
{
  return std::make_shared<Enemy>(name, health, base_damage, base_armor, enemy_resistances);
}

std::shared_ptr<Entity> EntityFactory::createWeapon(std::string name, int durability, int base_damage,
                                                    std::string type, double crit_chance)
{
  return std::make_shared<Weapon>(name, durability, base_damage, type, crit_chance);
}

std::shared_ptr<Entity> EntityFactory::createPlayer(std::string name, int health, int base_damage,
                                                    int base_armor)
{
  return std::make_shared<Player>(name, health, base_damage, base_armor);
}