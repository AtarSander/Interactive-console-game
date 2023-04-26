#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "../entity.hpp"

TEST_CASE("Test Entity attack method") {
    std::shared_ptr<Entity> entity1 = std::make_shared<Entity>("Entity 1", 100, 10, 20);
    std::shared_ptr<Entity> entity2 = std::make_shared<Entity>("Entity 2", 80, 5, 10);

    entity1->attack(entity2);

    REQUIRE(entity2->getHealth() == 72);
}

TEST_CASE("Test Entity defend method with armor") {
    std::shared_ptr<Entity> entity = std::make_shared<Entity>("Entity", 100, 10, 20);

    entity->defend(10);

    REQUIRE(entity->getBaseArmor() == 18);
    REQUIRE(entity->getHealth() == 92);
}

TEST_CASE("Test Entity defend method without armor") {
    std::shared_ptr<Entity> entity = std::make_shared<Entity>("Entity", 100, 10, 0);

    entity->defend(10);

    REQUIRE(entity->getHealth() == 90);
}

TEST_CASE("Test Entity exists method when health is greater than 0") {
    std::shared_ptr<Entity> entity = std::make_shared<Entity>("Entity", 100, 10, 20);

    REQUIRE(entity->exists() == true);
}

TEST_CASE("Test Entity exists method when health is equal to 0") {
    std::shared_ptr<Entity> entity = std::make_shared<Entity>("Entity", 0, 10, 20);

    REQUIRE(entity->exists() == false);
}