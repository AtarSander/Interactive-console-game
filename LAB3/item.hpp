#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item
{
    public:
        Item(std::string name, unsigned int uses): name(name), uses(uses){};
        std::string get_name() const;
        std::string get_type() const;
        unsigned int get_uses() const;
        Item& operator--();
        unsigned int check_uses();
    private:
        const std::string name;
        const std::string type;
        unsigned int uses;
};
#endif