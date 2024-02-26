cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME POSTGRE_SQL)
add_library(${LIBRARY_NAME} INTERFACE)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

target_link_libraries(${LIBRARY_NAME} INTERFACE
        ${PQXX_LIB}
        ${PQ_LIB}
)