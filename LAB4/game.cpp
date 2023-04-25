#include "game.hpp"
#include "player.cpp"
#include <memory>
#include <algorithm>
#include <iostream>

void Game::play(std::shared_ptr<Player> player1)
{
    player = std::move(player1);
    current_enemy = std::move(list_of_enemies.front());
    this -> selectWeapon(this -> inputStr());
    player -> addWeapon(current_weapon);
    while(!list_of_enemies.empty())
    {
        if(!current_enemy -> exists())
        {
            list_of_enemies.pop_front();
            current_enemy = std::move(list_of_enemies.front());
            this -> selectWeapon(this -> inputStr());
            player -> addWeapon(current_weapon);
        }
        this -> round();
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
    this -> printResult(player_damage, player_health, enemy_health, enemy_damage);
}

void Game::printResult(int player_damage, int player_health, int enemy_health, int enemy_damage)
{
    std::string enemy_name = current_enemy -> getName();
    std::string player_name = player -> getName();
    std::cout << enemy_name << " took " << enemy_damage <<
    " damage.\n He has " << enemy_health << " health points left.\n";
    std::cout << player_name << " took " << player_damage <<
    " damage.\n He has " << player_health << " health points left.\n";
}

void Game::selectWeapon(std::string name)
{
    for (auto& weapon : list_of_weapons)
    {
        if (weapon -> getName() == name)
        {
        current_weapon = std::move(weapon);
        }
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

void Game::addEnemy(std::unique_ptr<Entity> enemy)
{
    list_of_enemies.push_back(enemy);
}

void Game::addWeapon(std::unique_ptr<Entity> weapon)
{
    list_of_weapons.push_back(weapon);
}