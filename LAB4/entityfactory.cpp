#include "entity.hpp"
#include "enemy.hpp"
#include "weapon.hpp"
#include "entityfactory.hpp"
#include <memory>
#include <string>
#include <stdexcept>

std::unique_ptr<Entity> EntityFactory::createEntity(EntityType type, std::string name,
                                         int health, int base_damage,
                                         int base_armor, std::string weapon_type,
                                         std::map<std::string, double> enemy_resistances)
{
  switch (type)
  {
    case EntityType::Enemy:
      return createEnemy(name, health, base_damage, base_armor, enemy_resistances);
    case EntityType::Weapon:
      return createWeapon(name, base_damage, weapon_type);
    default:
      throw std::invalid_argument("Invalid entity type");
  }
}

std::unique_ptr<Entity> EntityFactory::createEnemy(std::string name, unsigned int health,
    unsigned int base_damage, unsigned int base_armor, std::map<std::string, double> enemy_resistances)
{
  return std::make_unique<Enemy>(name, health, base_damage, base_armor, enemy_resistances);
}

std::unique_ptr<Entity> EntityFactory::createWeapon(std::string name, unsigned int base_damage, std::string type)
{
  return std::make_unique<Weapon>(name, base_damage, type);
}