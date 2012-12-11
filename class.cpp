#include "class.hpp"
Room::Room(const std::string& Name):name(Name)
{
}

const std::string& Room::Name() const
{
	return name;
}

void Room::Name(const std::string& Name)
{
	name=Name;
}