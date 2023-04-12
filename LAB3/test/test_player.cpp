#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../player.hpp"

TEST_CASE("Player class tests")
{
    SECTION("Name getter returns correct name")
    {
        Player player("Alice", 100);
        REQUIRE(player.get_name() == "Alice");
    }

    SECTION("Health getter returns correct health")
    {
        Player player("Bob", 75);
        REQUIRE(player.get_health() == 75);
    }

    SECTION("Setting valid health value updates health")
    {
        Player player("Charlie", 50);
        player.set_health(75);
        REQUIRE(player.get_health() == 75);
    }

    SECTION("Setting invalid health value throws an exception")
    {
        Player player("Dave", 100);
        REQUIRE_THROWS_AS(player.set_health(-50), std::invalid_argument);
    }
}

TEST_CASE("Player add_item method")
{
    Player player("John", 100);

    SECTION("Adding an item to empty equipment")
    {
        Item item("Sword", "Weapon", 10);
        player.add_item(item);

        REQUIRE(player.get_equipment().size() == 1);
        REQUIRE(player.get_equipment().front().get_name() == "Sword");
        REQUIRE(player.get_equipment().front().get_type() == "Weapon");
        REQUIRE(player.get_equipment().front().get_uses() == 10);
    }

    SECTION("Adding an item to non-empty equipment")
    {
        Item item1("Sword", "Weapon", 10);
        Item item2("Potion", "Consumable", 1);
        player.add_item(item1);
        player.add_item(item2);

        REQUIRE(player.get_equipment().size() == 2);
        REQUIRE(player.get_equipment().front().get_name() == "Sword");
        REQUIRE(player.get_equipment().back().get_name() == "Potion");
    }
}

TEST_CASE("Player find_useful_item method")
{
    Player player("John", 100);

    SECTION("Finding a useful item")
    {
        Item item1("Sword", "Weapon", 10);
        Item item2("Potion", "Consumable", 1);
        player.add_item(item1);
        player.add_item(item2);

        unsigned int result = player.find_useful_item("Consumable");
        REQUIRE(result == 0);
        REQUIRE(player.get_equipment().size() == 1);
        REQUIRE(player.get_equipment().front().get_name() == "Sword");
    }

    SECTION("Not finding a useful item")
    {
        Item item("Sword", "Weapon", 10);
        player.add_item(item);

        unsigned int result = player.find_useful_item("Consumable");
        REQUIRE(result == 1);
        REQUIRE(player.get_equipment().size() == 1);
        REQUIRE(player.get_equipment().front().get_name() == "Sword");
    }

    SECTION("Using up the last use of an item")
    {
        Item item("Potion", "Consumable", 1);
        player.add_item(item);

        unsigned int result = player.find_useful_item("Consumable");
        REQUIRE(result == 0);
        REQUIRE(player.get_equipment().empty());
    }

    SECTION("Using up a use of an item")
    {
        Item item("Potion", "Consumable", 2);
        player.add_item(item);

        unsigned int result = player.find_useful_item("Consumable");
        REQUIRE(result == 0);
        REQUIRE(player.get_equipment().size() == 1);
        REQUIRE(player.get_equipment().front().get_name() == "Potion");
        REQUIRE(player.get_equipment().front().get_uses() == 1);
    }
}