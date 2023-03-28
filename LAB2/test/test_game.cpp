#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../chapter.hpp"
#include "../game.hpp"
#include <sstream>

TEST_CASE("Game constructor and getter functions")
{
    Player player1("John", 100);
    Game game(player1);
    REQUIRE(game.get_chapter_count() == 0);
}

TEST_CASE("Game input_option function")
{
    Player player1("John", 100);
    Game game(player1);

    Chapter chapter(123);
    chapter.read_from_file("../seed_0.txt");
    game.add_chapter(chapter);

    std::istringstream input("turn back\n");
    std::streambuf* cin_backup = std::cin.rdbuf(input.rdbuf());

    REQUIRE(game.input_option() == "turn back");

    std::cin.rdbuf(cin_backup);
}
