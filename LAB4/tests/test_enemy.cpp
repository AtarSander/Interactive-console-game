#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../enemy.hpp"
#include <memory>
#include <map>


TEST_CASE("Test constructor")
{
    std::map<std::string, double> resistances = {{"fire", 0.5}, {"ice", 1.0}};
    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>("Enemy", 50, 5, 0, resistances);
    REQUIRE(enemy->getName() == "Enemy");
    REQUIRE(enemy->getHealth() == 50);
    REQUIRE(enemy->getBaseDamage() == 5);
    REQUIRE(enemy->getBaseArmor() == 0);
    REQUIRE(enemy->checkResistance("fire") == 0.5);
    REQUIRE(enemy->checkResistance("ice") == 1.0);
    REQUIRE(enemy->checkResistance("water") == 0.0);
}

TEST_CASE("Test attack and defend")
{
    std::map<std::string, double> resistances = {{"fire", 0.5}, {"ice", 1.0}};
    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>("Enemy", 50, 5, 0, resistances);
    std::shared_ptr<Enemy> player = std::make_shared<Enemy>("Player", 50, 10, 0, resistances);
    enemy->attack(player);
    REQUIRE(player->getHealth() == 45);
    player->attack(enemy);
    REQUIRE(enemy->getHealth() == 40);
    player->attack(enemy);
    REQUIRE(enemy->getHealth() == 30);
    enemy->defend(2);
    REQUIRE(enemy->getHealth() == 28);
    enemy->defend(6);
    REQUIRE(enemy->getHealth() == 22);
}

TEST_CASE("Test resistances")
{
    std::map<std::string, double> resistances = {{"fire", 0.5}, {"ice", 1.0}};
    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>("Enemy", 50, 5, 0, resistances);
    REQUIRE(enemy->checkResistance("fire") == 0.5);
    REQUIRE(enemy->checkResistance("ice") == 1.0);
    enemy->addResistance("water", 0.25);
    REQUIRE(enemy->checkResistance("water") == 0.25);
}
