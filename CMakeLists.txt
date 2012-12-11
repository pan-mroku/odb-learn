CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(odb-learn)
SET(LIBS odb-sqlite odb)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O2 -DDATABASE_SQLITE")

ADD_EXECUTABLE(create create.cpp)
TARGET_LINK_LIBRARIES(create ${LIBS})

ADD_CUSTOM_COMMAND(
  OUTPUT person-odb.hxx person-odb.cxx person-odb.ixx class-odb.hxx class-odb.cxx class-odb.ixx
  COMMAND odb --database sqlite --generate-query --generate-schema person.hpp class.hpp
  DEPENDS person.hpp class.hpp
)

ADD_EXECUTABLE(create_add_save create_add_save.cpp person.hpp person-odb.hxx person-odb.cxx)
TARGET_LINK_LIBRARIES(create_add_save ${LIBS})

ADD_EXECUTABLE(to-many to-many.cpp person.hpp person-odb.hxx person-odb.cxx class.hpp class.cpp class-odb.hxx class-odb.cxx)
TARGET_LINK_LIBRARIES(to-many ${LIBS})
