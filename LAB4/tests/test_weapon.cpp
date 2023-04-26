#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../weapon.hpp"
#include <memory>


TEST_CASE("Regular attack")
{
    std::shared_ptr<Entity> target = std::make_shared<Entity>("Target", 100, 10, 0);
    Weapon weapon("Sword", 100, 20, "Slash", 0);

    // Test regular attack
    weapon.attack(target);
    REQUIRE(target->getHealth() == 80);
    REQUIRE(weapon.getHealth() == 99);
}

TEST_CASE("Test critical hit")
{
    std::shared_ptr<Entity> target = std::make_shared<Entity>("Target", 500, 10, 0);
    Weapon weapon("Sword", 100, 20, "Slash", 1);
    weapon.attack(target);
    REQUIRE(target->getHealth() == 100);
    REQUIRE(weapon.getHealth() == 99);
}

TEST_CASE("Test attacking with 0 durability")
{
    std::shared_ptr<Entity> target = std::make_shared<Entity>("Target", 100, 10, 0);
    Weapon weapon("Sword", 100, 20, "Slash", 1);
    weapon.setHealth(0);
    weapon.attack(target);
    REQUIRE(target->getHealth() == 100);
    REQUIRE(weapon.getHealth() == 0);
}


TEST_CASE("getType method")
{
    Weapon weapon("Sword", 100, 20, "Slash", 0.5);
    REQUIRE(weapon.getType() == "Slash");
}