cmake_minimum_required(VERSION 2.8)
project (odb-learn)
set (LIBS odb odb-sqlite)

add_executable (create create.cpp)
target_link_libraries(create ${LIBS})

add_executable (create_add_save create_add_save.cpp)
target_link_libraries(create_add_save ${LIBS})