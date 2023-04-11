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