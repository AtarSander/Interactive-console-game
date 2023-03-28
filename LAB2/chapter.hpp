#include <string>
#include <list>

class Chapter
{
    public:
        Chapter(unsigned int seed) : _seed(seed){};
        void print_story();
        unsigned int get_seed() const;
        unsigned int outcome(std::string response);
    private:
        std::list<std::string> _list_of_options;
        unsigned int _seed;
};