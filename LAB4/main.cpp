#include <iostream>
#include "entityfactory.hpp"
#include "game.hpp"


int main()
{
    EntityFactory factory;
    Game game;
    std::string name, weapon_type, resistance_name;
    std::map<std::string, double> enemy_resistances;
    int n;
    double resistance_value;
    std::cout << "How many enemies do you want to create: ";
    std::cin >> n;

    std::cout << "\nCreate your enemies by typing their name and resistance.\n\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << std::endl;
        std::cout << "Resistance name: ";
        std::cin >> resistance_name;
        std::cout << std::endl;
        resistance_value = randomizeFloat(1);
        enemy_resistances[resistance_name] = resistance_value;
        std::shared_ptr<Entity> enemy = factory.createEntity(EntityType::Enemy, name, 0, 0,
                                                                                0, enemy_resistances);
        game.addEnemy(std::move(enemy));
    }

    std::cout << "How many weapons do you want to create: ";
    std::cin >> n;

    std::cout << "\nCreate your Weapons by typing their name and type.\n\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << std::endl;
        std::cout << "Weapon type: ";
        std::cin >> weapon_type;
        std::cout << std::endl;
        std::shared_ptr<Entity> weapon = factory.createEntity(EntityType::Weapon, name, 0, 0, 0,
                                                                                 {}, weapon_type, 0 );
        game.addWeapon(std::move(weapon));
    }


    std::cout << "Type in your name: ";
    std::cin >> name;
    std::shared_ptr<Player> player1 = std::make_shared<Player>(name, 100, 10, 30);
    game.play(player1);

    return 0;
}