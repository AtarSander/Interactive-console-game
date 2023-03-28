#include <string>

class Player
{
    public:
        Player(std::string name, unsigned int health) : _name(name), _health(health){};
        std::string get_name() const;
        unsigned int get_health() const;
        void set_health(unsigned int new_health);
    private:
        std::string _name;
        unsigned int _health;
};