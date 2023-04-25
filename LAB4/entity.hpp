#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>
#include <memory>


class Entity
{
    public:
    Entity(std::string name, int health, int base_damage, int base_armor) :
    name(name), health(health), base_damage(base_damage), base_armor(base_armor){};
    virtual ~Entity() = default;
    virtual void attack(std::shared_ptr<Entity> other);
    virtual void defend(int damage);
    virtual bool exists() const;
    void setHealth(int new_health);
    void setArmor(int new_armor);
    void transferParameter(std::string data);

    std::string getName() const;
    std::string getParameter() const;
    int getHealth() const;
    int getBaseDamage() const;
    int getBaseArmor() const;

    private:
        std::string const name;
        int health;
        int base_damage;
        int base_armor;
        std::string parameter = "";
};

#endif