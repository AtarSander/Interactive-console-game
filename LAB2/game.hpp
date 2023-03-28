#include "chapter.hpp"
#include "player.hpp"
#include <map>

class Game
{
    public:
        Game(Player player) : _player(player) {};
        void play();
        void set_current_seed(unsigned int new_seed);
        void wrong_input() const;
        void change_player_state();
        void player_damage(int value);
        unsigned int get_chapter_count();
        std::string input_option();

    private:
        std::map<unsigned int, Chapter> _map_of_chapters;
        unsigned int current_seed;
        Player _player;
};