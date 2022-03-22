cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME CS008_SFML_Typing)

project(${PROJECT_NAME})

#if (WIN32)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
#endif ()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ResourceHolder.cpp ResourceHolder.h States.cpp States.h StatesENUM.h RichTextFormat.cpp RichTextFormat.h Typing.cpp Typing.h MultiText.cpp MultiText.h Letter.cpp Letter.h GUIComponent.cpp GUIComponent.h TextInput.cpp TextInput.h)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
    else ()
        add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    endif ()

    set(SFML_ROOT C:/SFML-2.5.1)
    set(SFML_STATIC_LIBRARIES TRUE)

    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
    #set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
    find_package(SFML REQUIRED COMPONENTS audio graphics window system)
    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif ()

else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
    find_package(SFML COMPONENTS graphics audio REQUIRED)
endif()