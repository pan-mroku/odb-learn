// file      : access/person.hpp
// copyright : not copyrighted - public domain

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <cstddef> // std::size_t

#include <odb/core.hxx>

#include "class.hpp"

#pragma db object
class person
{
public:
  person (const std::string& first,
          const std::string& last,
          unsigned short age)
      : first_ (first), last_ (last), age_ (age)
  {
	  //room_=NULL;
  }

  const Room& MyRoom() const
  {
	  return *room_;
  }

  void MyRoom(Room& Room)
  {
	  room_=&Room;
  }

  const std::string&
  first () const
  {
    return first_;
  }

  const std::string&
  last () const
  {
    return last_;
  }

  unsigned short
  age () const
  {
    return age_;
  }

  void
  age (unsigned short age)
  {
    age_ = age;
  }

private:
  friend class odb::access;

  person () {}

  #pragma db id auto
  unsigned long id_;

  std::string first_;
  std::string last_;
  unsigned short age_;

#pragma db not_null
 Room* room_;

};

/*#pragma db view object(person)
struct person_stat
{
  #pragma db column("count(" + person::id_ + ")")
  std::size_t count;

  #pragma db column("min(" + person::age_ + ")")
  unsigned short min_age;

  #pragma db column("max(" + person::age_ + ")")
  unsigned short max_age;
  };*/

#pragma db object
class Key
{
private:
	friend class odb::access;
	Key(){};

#pragma db id auto
	unsigned int id;

#pragma db not_null
	person* owner;

	std::string brand;

public:
	
	Key(const std::string& Brand, const person& Owner):brand(Brand)
	{
		owner=const_cast<person*>(&Owner);
	}

	const std::string Brand() const
	{
		return brand;
	}

	void Brand(const std::string Brand)
	{
		brand=Brand;
	}

	const person& Owner() const
	{
		return *owner;
	}
};

#endif // PERSON_HPP
