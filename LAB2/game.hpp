#include "chapter.hpp"
#include "player.hpp"
#include <map>

class Game
{
    public:
        Game(){};
        void play();
        unsigned int get_chapter_count();
        void set_current_seed(unsigned int new_seed);
        std::string input_option();
        void wrong_input();
    private:
        std::map<unsigned int, Chapter> _map_of_chapters;
        unsigned int current_seed;
};