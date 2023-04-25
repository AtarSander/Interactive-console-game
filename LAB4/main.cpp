#include <iostream>
#include "entityfactory.hpp"
#include "game.hpp"


int main()
{
    EntityFactory factory;
    Game game;
    std::string name, weapon_type, resistance_name;
    int health, base_damage, base_armor;
    std::map<std::string, double> enemy_resistances;
    double crit_chance, resistance_value;
    for (int i = 0; i < 1; i++)
    {
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << std::endl;
        std::cout << "Health: ";
        std::cin >> health;
        std::cout << std::endl;
        std::cout << "Base damage: ";
        std::cin >> base_damage;
        std::cout << std::endl;
        std::cout << "Base armor: ";
        std::cin >> base_armor;
        std::cout << std::endl;
        std::cout << "Resistance name: ";
        std::cin >> resistance_name;
        std::cout << std::endl;
        std::cout << "Resistance value: ";
        std::cin >> resistance_value;
        std::cout << std::endl;
        enemy_resistances[resistance_name] = resistance_value;
        std::shared_ptr<Entity> enemy = factory.createEntity(EntityType::Enemy, name, health, base_damage,
                                                                                base_armor, enemy_resistances);
        game.addEnemy(std::move(enemy));
    }

    for (int i = 0; i < 1; i++)
    {
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << std::endl;
        std::cout << "Weapon type: ";
        std::cin >> weapon_type;
        std::cout << std::endl;
        std::cout << "Durability: ";
        std::cin >> health;
        std::cout << std::endl;
        std::cout << "Base damage: ";
        std::cin >> base_damage;
        std::cout << std::endl;
        std::cout << "Crit chance: ";
        std::cin >> crit_chance;
        std::cout << std::endl;
        enemy_resistances[resistance_name] = resistance_value;
        std::shared_ptr<Entity> weapon = factory.createEntity(EntityType::Weapon, name, health, base_damage, 0,
                                                                                 {}, weapon_type, crit_chance );
        game.addWeapon(std::move(weapon));
    }
    std::shared_ptr<Player> player1 = std::make_shared<Player>("Alek", 100, 10, 30);
    game.play(player1);

    return 0;
}