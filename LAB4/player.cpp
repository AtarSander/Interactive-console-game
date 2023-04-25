#include "entity.hpp"
#include <memory>
#include <map>
#include <string>

class Player : public Entity
{
    public:
        Player(std::string name, unsigned int health,
              unsigned int base_damage, unsigned int base_armor) :
        Entity(name, health, base_damage, base_armor) {}

        virtual void attack(std::shared_ptr<Entity> other)
        {
            current_weapon -> attack(other);
        };
        void addWeapon(std::shared_ptr<Entity> weapon)
        {
            current_weapon = std::move(weapon);
        };
    private:
        unsigned int strength;
        std::shared_ptr<Entity> current_weapon;
};