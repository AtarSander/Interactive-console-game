#include <string>
#include <list>
#include <map>

class Chapter
{
    public:
        Chapter(unsigned int seed) : _seed(seed){};
        std::string get_story() const;
        unsigned int get_seed() const;
        unsigned int outcome(std::string response);
    private:
        std::string _story;
        std::map<std::string, unsigned int> _list_of_options;
        unsigned int _seed;
};