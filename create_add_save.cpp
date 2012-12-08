#include <iostream>
//#include <odb/database.hxx>

//sqlite
//#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "person.hpp"
#include "person-odb.hxx"

int main()
{
  odb::sqlite::database db("test.db", SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);

  {
    person john ("John", "Doe", 31);
    person jane ("Jane", "Doe", 29);

    odb::core::transaction t (db.begin ());
    odb::schema_catalog::create_schema (db);
    db.persist(john);
    db.persist(jane);
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


  std::cout<<db.name()<<std::endl;
  return 0;
}
