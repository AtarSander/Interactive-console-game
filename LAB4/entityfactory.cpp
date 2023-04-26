#include "entity.hpp"
#include "enemy.hpp"
#include "weapon.hpp"
#include "player.hpp"
#include "entityfactory.hpp"
#include <memory>
#include <string>
#include <stdexcept>
#include <random>

std::shared_ptr<Entity> EntityFactory::createEntity(EntityType type, std::string name,
                                         int health, int base_damage,
                                         int base_armor, std::map<std::string, double> enemy_resistances,
                                         std::string weapon_type,
                                         double crit_chance)
{
  if (health == 0)
  {
    health = randomizeInt(50, 100);
  }
  if (base_damage == 0)
  {
     base_damage = randomizeInt(5, 20);
  }
  if (base_armor == 0)
  {
     base_armor = randomizeInt(5, 20);
  }
  if (base_damage == 0)
  {
     base_damage = randomizeInt(5, 20);
  }
  if (crit_chance == 0)
  {
    crit_chance = randomizeFloat(0.2);
  }
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

int randomizeInt(int border_down, int border_up)
{
    if (border_down > border_up)
    {
        return 0;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(border_down, border_up);
    return dis(gen);
}

double randomizeFloat(double border)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, border);
    return dis(gen);
}