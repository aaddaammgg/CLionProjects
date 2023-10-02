cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME Kings_Corner)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ResourceHolder.cpp ResourceHolder.h States.cpp States.h StatesENUM.h GUIComponent.cpp GUIComponent.h MouseEvents.cpp MouseEvents.h Application.cpp Application.h GUIAdapter.cpp GUIAdapter.h GUI_Circle.cpp GUI_Circle.h EventHandlerCallbacks.h EventHandlerCallbacks.cpp
        SuitsENUM.h
        SuitsColorENUM.h
        SFMLCard.cpp
        SFMLCard.h
        SFMLCardCorner.cpp
        SFMLCardCorner.h
        BaseCard.cpp
        BaseCard.h
        BaseRank.cpp
        BaseRank.h
        RanksENUM.h
        BaseSuit.cpp
        BaseSuit.h
        Deck.cpp
        Deck.h
        CardHand.cpp
        CardHand.h
        CardPile.cpp
        CardPile.h
        CompassENUM.h
        RoundedRectangleShape.cpp
        RoundedRectangleShape.h
        SFMLDeck.cpp
        SFMLDeck.h
        SFMLCardOutline.cpp
        SFMLCardOutline.h _DEFINITIONS.h)

if (WIN32)
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
    else ()
        add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    endif ()

    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

    find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
    endif ()
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
    find_package(SFML COMPONENTS graphics audio REQUIRED)
endif ()