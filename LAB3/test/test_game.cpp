#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../chapter.hpp"
#include "../game.hpp"
#include "../player.hpp"
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
    chapter.read_from_file("seeds/seed_0.txt");
    game.add_chapter(chapter);

    std::istringstream input("turn back\n");
    std::streambuf* cin_backup = std::cin.rdbuf(input.rdbuf());

    REQUIRE(game.input_option() == "turn back");

    std::cin.rdbuf(cin_backup);
}

TEST_CASE("Game add_chapter function")
{
    Player player1("John", 100);
    Game game(player1);

    Chapter chapter(123);
    chapter.read_from_file("seeds/seed_0.txt");
    game.add_chapter(chapter);
    SECTION("Correct chapter_count")
    {
        REQUIRE(game.get_chapter_count() == 1);
    }

    SECTION("Correct get_chapter and outcome")
    {
    REQUIRE(game.get_chapter(12).outcome("turn back") == 2);
    REQUIRE(game.get_chapter(12).outcome("light the torch") == 1);
    }
}

TEST_CASE("Change player state")
{
    Player player1("John", 100);
    Game game(player1);
    game.change_player_state();
    REQUIRE(game.get_player().get_health() < 100);
}

TEST_CASE("Test config_chapters method")
{
    Player player1("Tester", 100);
    Game game(player1);
    std::string filename = "seeds/config.txt";
    game.config_chapters(filename);

    Chapter chapter1 = game.get_chapter(12);

    REQUIRE(chapter1.get_story() == "Welcome adventurer, to a world filled with magic and mystery. You are a treasure hunter, seeking fortune and glory in the far corners of this fantastical land. The journey ahead will be perilous, but the rewards could be great. Are you ready to embark on this adventure?\r\n\r\nYour quest begins at the entrance of a dark and foreboding cave. Legend has it that deep within its depths lies a treasure beyond your wildest dreams. As you take your first steps into the cave, the air grows colder and the darkness thickens. You can hear the sound of dripping water echoing off the walls.\r\n\r\nDo you light the torch and venture forth into the darkness, or do you turn back and search for another path?\r\n");
    REQUIRE(chapter1.outcome("light the torch") == 1);
    REQUIRE(chapter1.outcome("turn back") == 2);
}

TEST_CASE("Game save_game method")
{
    Player player1("Tester", 100);
    Game game(player1);
    game.set_current_seed(1);
    game.save_game("test_save.txt");

    std::ifstream save_file("test_save.txt");
    std::string line;
    getline(save_file, line);
    REQUIRE(line == "0"); //previous_seed
    getline(save_file, line);
    REQUIRE(line == "Tester"); //player name
    getline(save_file, line);
    REQUIRE(line == "100"); //player health
    save_file.close();

    std::remove("test_save.txt");
}

TEST_CASE("Game load_game method")
{
    Player player1("Tester", 100);
    Game game(player1);
    std::string filename = "test_save.txt";
    std::ofstream save_file(filename);
    save_file << "3\nJohn\n50\n3600\n";
    save_file.close();

    game.load_game(filename);

    REQUIRE(game.get_current_seed() == 3);
    REQUIRE(game.get_player().get_name() == "John");
    REQUIRE(game.get_player().get_health() == 50);

    std::remove(filename.c_str());
}