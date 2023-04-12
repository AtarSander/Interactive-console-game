#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../item.hpp"

TEST_CASE("Test Item getters", "[Item]")
{
    Item item("sword", "weapon", 10);
    REQUIRE(item.get_name() == "sword");
    REQUIRE(item.get_type() == "weapon");
    REQUIRE(item.get_uses() == 10);
}

TEST_CASE("Test Item decrement operator", "[Item]")
{
    Item item("potion", "consumable", 3);
    --item;
    REQUIRE(item.get_uses() == 2);
    --item;
    --item;
    REQUIRE(item.get_uses() == 0);
}

TEST_CASE("Test Item check_uses", "[Item]")
{
    Item item("shield", "armor", 2);
    REQUIRE(item.check_uses() == 0);
    --item;
    REQUIRE(item.check_uses() == 0);
    --item;
    REQUIRE(item.check_uses() == 1);
}