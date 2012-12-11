#include <iostream>
//#include <odb/database.hxx>

//sqlite
//#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "person.hpp"
#include "person-odb.hxx"
#include "class.hpp"
#include "class-odb.hxx"

int main()
{
  odb::sqlite::database db("test.db", SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  

  {
    person john ("John", "Doe", 31);
    person jane ("Jane", "Doe", 29);
	person bob("Bob", "Builder", 45);
	Key gerda("Gerda", jane);
	Key yeti("Yeti", john);
	Room r("234");
	john.MyRoom(r);
	bob.MyRoom(r);
	jane.MyRoom(r);

    odb::core::transaction t (db.begin ());
    odb::schema_catalog::create_schema (db); //tworzenie tabel wg wygenerowanego schema

    db.persist(r);
	db.persist(john);
	db.persist(jane);
	db.persist(bob);
	db.persist(gerda);
    db.persist(yeti);
	

	t.commit();
  }



  {
    odb::core::transaction t (db.begin ());
	odb::result<person> r (db.query<person>());
    odb::result<person>::iterator i (r.begin ());

    for (odb::result<person>::iterator i (r.begin ()); i != r.end (); ++i)
      std::cout << "Hello, " << i->first () << " " << i->last () << "!" << std::endl;
	
    t.commit ();
  }

  {
    odb::core::transaction t (db.begin ());
	odb::result<Key> r (db.query<Key>());
    odb::result<Key>::iterator i (r.begin ());

    for (odb::result<Key>::iterator i (r.begin ()); i != r.end (); ++i)
		std::cout << i->Brand() << " key owned by "<< i->Owner().first () << " " << i->Owner().last () << " from room " <<i->Owner().MyRoom().Name()<<"!"<< std::endl;
	
    t.commit ();
  }

  std::cout<<db.name()<<std::endl;
  std::cin.get();
  return 0;
}
