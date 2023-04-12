#define CATCH_CONFIG_MAIN
#include "../chapter.hpp"
#include "catch.hpp"

TEST_CASE("Chapter constructor and getter functions")
{
    SECTION("Default chapter gets correct parameters")
    {
    Chapter chapter;
    REQUIRE(chapter.get_story() == "");
    REQUIRE(chapter.get_seed() == 0);
    }

    SECTION("Consctructor gives correct properities")
    {
    Chapter chapter2(123);
    REQUIRE(chapter2.get_story() == "");
    REQUIRE(chapter2.get_seed() == 123);
    }
}

TEST_CASE("Chapter outcome function")
{
    Chapter chapter(123);
    chapter.read_from_file("seeds/seed_0.txt");

    REQUIRE(chapter.outcome("light the torch") == 1);
    REQUIRE(chapter.outcome("turn back") == 2);
}

TEST_CASE("Chapter read_from_file method")
{
    Chapter chapter;
    chapter.read_from_file("seeds/seed_0.txt");

    SECTION("Story is read correctly")
    {
        REQUIRE(chapter.get_story() == "Welcome adventurer, to a world filled with magic and mystery. You are a treasure hunter, seeking fortune and glory in the far corners of this fantastical land. The journey ahead will be perilous, but the rewards could be great. Are you ready to embark on this adventure?\r\n\r\nYour quest begins at the entrance of a dark and foreboding cave. Legend has it that deep within its depths lies a treasure beyond your wildest dreams. As you take your first steps into the cave, the air grows colder and the darkness thickens. You can hear the sound of dripping water echoing off the walls.\r\n\r\nDo you light the torch and venture forth into the darkness, or do you turn back and search for another path?\r\n");
    }

    SECTION("Seed is read correctly")
    {
        REQUIRE(chapter.get_seed() == 12);
    }

    SECTION("Options are read correctly")
    {
        REQUIRE(chapter.outcome("light the torch") == 1);
        REQUIRE(chapter.outcome("turn back") == 2);
        REQUIRE(chapter.outcome("search for another path") == 2);
    }
}