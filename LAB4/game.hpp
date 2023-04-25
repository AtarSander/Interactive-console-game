#ifndef GAME_HPP
#define GAME_HPP
#include "entityfactory.hpp"
#include <list>
#include <memory>
class Game
{
    public:
        void play(std::shared_ptr<Player> player1);
        void round();
        void printResult(int player_damage, int player_health, int enemy_health, int enemy_damage);
        void addEnemy(std::unique_ptr<Entity> enemy);
        void addWeapon(std::unique_ptr<Entity> weapon);
        void selectWeapon(std::string name);
        std::string inputStr();
    private:
        std::list<std::unique_ptr<Entity>> list_of_enemies;
        std::list<std::unique_ptr<Entity>> list_of_weapons;
        std::shared_ptr<Entity> current_enemy;
        std::shared_ptr<Entity> current_weapon;
        std::shared_ptr<Player> player;
};
#endif