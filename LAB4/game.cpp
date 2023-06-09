#include "game.hpp"
#include "player.hpp"
#include <memory>
#include <algorithm>
#include <iostream>

void Game::play(std::shared_ptr<Player> player1)
{
    player = std::move(player1);
    current_enemy = list_of_enemies.front();
    this -> selectWeapon(this -> inputStr());
    player -> addWeapon(current_weapon);
    while(!list_of_enemies.empty())
    {
        if(!current_enemy -> exists())
        {
            current_enemy = list_of_enemies.front();
            list_of_enemies.pop_front();
            if(!list_of_enemies.empty())
            {
                this -> selectWeapon(this -> inputStr());
                player -> addWeapon(current_weapon);
            }


        }
        if (!player -> exists())
        {
            std::cout<<"You are dead.\n";
            break;
        }
        if (!list_of_enemies.empty())
        {
            this -> round();
        }

    }
    exit(0);
}

void Game::round()
{
    int player_damage, player_health, enemy_health, enemy_damage;

    enemy_damage = current_enemy -> getHealth();
    player_damage = player -> getHealth();

    player -> attack(current_enemy);
    current_enemy -> attack(player);

    player_health = player -> getHealth();
    enemy_health = current_enemy -> getHealth();

    enemy_damage = enemy_damage - enemy_health;
    player_damage = player_damage - player_health;

    if (player_health < 0) player_health = 0;
    if (enemy_health < 0) enemy_health = 0;
    this -> printResult(player_damage, player_health, enemy_health, enemy_damage);
}

void Game::printResult(int player_damage, int player_health, int enemy_health, int enemy_damage)
{
    std::string enemy_name = current_enemy -> getName();
    std::string player_name = player -> getName();
    std::cout << enemy_name << " took " << enemy_damage <<
    " damage.\nHe has " << enemy_health << " health points left.\n";
    std::cout << player_name << " took " << player_damage <<
    " damage.\nHe has " << player_health << " health points left.\n\n";
}

void Game::selectWeapon(std::string name)
{
    bool found_weapon = false;
    for (auto& weapon : list_of_weapons)
    {
        if (weapon->getName() == name)
        {
            current_weapon = weapon;
            found_weapon = true;
            break;
        }
    }
    if (!found_weapon)
    {
        std::cout << "Invalid weapon name. Please try again." << std::endl;
        selectWeapon(inputStr());
    }
    else
    {
        std::cout << "Selected weapon: " << current_weapon->getName() << std::endl;
    }
}

std::string Game::inputStr()
{
    std::string value="";
    std::cout << "Select weapon by name: ";
    std::cin >> value;
    std::cout << std::endl;
    return value;
}

void Game::addEnemy(std::shared_ptr<Entity> enemy)
{
    list_of_enemies.push_back(enemy);
}

void Game::addWeapon(std::shared_ptr<Entity> weapon)
{
    list_of_weapons.push_back(weapon);
}