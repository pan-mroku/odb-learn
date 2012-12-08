CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(odb-learn)
SET(LIBS odb-sqlite odb)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O2 -DDATABASE_SQLITE")

ADD_EXECUTABLE(create create.cpp)
TARGET_LINK_LIBRARIES(create ${LIBS})

ADD_CUSTOM_COMMAND(
  OUTPUT person-odb.hxx person-odb.cxx person-odb.ixx
  COMMAND odb --database sqlite --generate-query --generate-schema person.hpp
  DEPENDS person.hpp
)

ADD_EXECUTABLE(create_add_save create_add_save.cpp person.hpp person-odb.hxx person-odb.cxx)
TARGET_LINK_LIBRARIES(create_add_save ${LIBS})