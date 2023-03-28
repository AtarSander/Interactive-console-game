#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include <string>
#include <list>
#include <map>

class Chapter
{
    public:
        Chapter() = default;
        Chapter(unsigned int seed) : _seed(seed){};
        std::string get_story() const;
        unsigned int get_seed() const;
        unsigned int outcome(std::string response);
        void read_from_file(std::string filename);
        void get_options();
    private:
        std::string _story;
        std::map<std::string, unsigned int> _list_of_options;
        unsigned int _seed;
};
#endif