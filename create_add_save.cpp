#include <iostream>
#include <odb/database.hxx>

//sqlite
#include <odb/connection.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

int main()
{
  odb::sqlite::database db("test");
  std::cout<<db.name()<<std::endl;
  return 0;
}
