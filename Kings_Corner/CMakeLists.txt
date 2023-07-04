cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME Kings_Corner)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ResourceHolder.cpp ResourceHolder.h States.cpp States.h StatesENUM.h GUIComponent.cpp GUIComponent.h MouseEvents.cpp MouseEvents.h Application.cpp Application.h GUIAdapter.cpp GUIAdapter.h GUI_Circle.cpp GUI_Circle.h EventHandlerCallbacks.h EventHandlerCallbacks.cpp)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
    else ()
        add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    endif ()

    set(SFML_ROOT C:/SFML-2.5.1)
    set(SFML_STATIC_LIBRARIES TRUE)

    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
    find_package(SFML REQUIRED COMPONENTS audio graphics window system)

    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif ()
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
    find_package(SFML COMPONENTS graphics audio REQUIRED)
endif ()