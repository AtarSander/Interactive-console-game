#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>
#include <memory>


class Entity
{
    public:
    Entity(std::string name, unsigned int health, unsigned int base_damage, unsigned int base_armor) :
    name(name), health(health), base_damage(base_damage), base_armor(base_armor){};
    virtual ~Entity();
    virtual void attack(std::shared_ptr<Entity> other);
    virtual void defend(unsigned int damage);
    virtual bool Exists() const;

    std::string getName() const;
    unsigned int getHealth() const;
    unsigned int getBaseDamage() const;
    unsigned int getBaseArmor() const;

    private:
        std::string const name;
        unsigned int health;
        unsigned int base_damage;
        unsigned int base_armor;
};

#endif