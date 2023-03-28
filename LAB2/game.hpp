#include "chapter.hpp"
#include "player.hpp"
#include <list>

class Game
{
    public:
        Game(){};
        void play();
        unsigned int get_chapter_count();
        std::string input_option();
    private:
        std::list<Chapter> list_of_levels;
};