CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(odb-learn)
SET(LIBS odb-sqlite odb)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O2 -DDATABASE_SQLITE")

ADD_EXECUTABLE(create create.cpp)
TARGET_LINK_LIBRARIES(create ${LIBS})

ADD_CUSTOM_COMMAND(
  OUTPUT person_-odb.hxx person_-odb.cxx person_-odb.ixx
  COMMAND odb --database sqlite --generate-query --generate-schema person_.hpp
  DEPENDS person_.hpp
)

ADD_EXECUTABLE(create_add_save create_add_save.cpp person_.hpp person_-odb.hxx person_-odb.cxx)
TARGET_LINK_LIBRARIES(create_add_save ${LIBS})

ADD_CUSTOM_COMMAND(
  OUTPUT person-odb.hxx person-odb.cxx person-odb.ixx class-odb.hxx class-odb.cxx class-odb.ixx
  COMMAND odb --database sqlite --generate-query --generate-schema person.hpp class.hpp
  DEPENDS person.hpp class.hpp
)

ADD_EXECUTABLE(to-one to-one.cpp person.hpp person-odb.hxx person-odb.cxx class.hpp class.cpp class-odb.hxx class-odb.cxx)
TARGET_LINK_LIBRARIES(to-one ${LIBS})
