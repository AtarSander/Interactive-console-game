#ifndef GAME_HPP
#define GAME_HPP
#include "chapter.hpp"
#include "player.hpp"
#include <map>
#include <chrono>

class Game
{
    public:
        Game(Player player1) : player(player1) {};
        void play();
        void set_current_seed(unsigned int new_seed);
        void wrong_input() const;
        void change_player_state();
        void player_damage(int value);
        void add_chapter(Chapter next_chapter);
        void config_chapters(std::string config_file);
        void save_game(std::string save_file);
        void load_game(std::string save_file);
        Chapter get_chapter(unsigned int seed);
        unsigned int get_chapter_count() const;
        Player get_player() const;
        unsigned int get_current_seed() const;
        std::string input_option();

    private:
        std::map<unsigned int, Chapter> map_of_chapters;
        unsigned int current_seed=1000;
        unsigned int previous_seed=0;
        unsigned int chap_count;
        unsigned int game_time = 0;
        Player player;
};
#endif