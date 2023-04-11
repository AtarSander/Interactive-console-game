#include "item.hpp"


std::string Item::get_name() const { return name; }

std::string Item::get_type() const { return type; }

unsigned int Item::get_uses() const { return uses; }

Item& Item::operator--()
{
  --uses;
  return *this;
}

unsigned int Item::check_uses()
{
    if (uses <= 0)
    {
        return 1;
    }
    return 0;
}