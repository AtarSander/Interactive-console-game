#ifndef GAME_HPP
#define GAME_HPP
#include "chapter.hpp"
#include "player.hpp"
#include <map>

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
        Chapter get_chapter(unsigned int seed);
        unsigned int get_chapter_count();
        Player get_player() const;
        unsigned int get_current_seed();
        std::string input_option();

    private:
        std::map<unsigned int, Chapter> map_of_chapters;
        unsigned int current_seed=12;
        Player player;
};
#endif