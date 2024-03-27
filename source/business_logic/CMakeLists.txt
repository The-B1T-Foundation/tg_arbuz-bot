cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME TG_ARBUZ_BOT_BUSINESS_LOGIC)

set(MODEL_HEADERS
        model/config/config_model.hpp
        model/user/user_model.hpp
)

set(MODEL_SOURCES
        model/config/config_model.cpp
        model/user/user_model.cpp
)

set(CONTROLLER_HEADERS
        controller/db/db_controller.hpp
        controller/config/config_controller.hpp
)

set(CONTROLLER_SOURCES
        controller/db/db_controller.cpp
        controller/config/config_controller.cpp
)

add_library(${LIBRARY_NAME} STATIC
        ${MODEL_HEADERS}
        ${CONTROLLER_HEADERS}
        ${MODEL_SOURCES}
        ${CONTROLLER_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ./)
target_link_libraries(${LIBRARY_NAME} PUBLIC UTILS POSTGRE_SQL)

include_directories(model)
include_directories(controller)