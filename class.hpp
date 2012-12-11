#ifndef CLASS_HPP
#define CLASS_HPP

#include <string>
#include <odb/core.hxx>

#pragma db object
class Room
{
private:
#pragma db id auto
	unsigned int id;

	Room(){};
	friend class odb::access;

	std::string name;

public:
	Room(const std::string& Name);

	const std::string& Name() const;

	void Name(const std::string& Name);
};

#endif