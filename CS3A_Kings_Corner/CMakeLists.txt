cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME CS3A_Kings_Corner)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp DEFINITIONS.h ResourceHolder.cpp ResourceHolder.h BaseCard.cpp BaseCard.h RanksENUM.h SuitsENUM.h BaseSuit.cpp BaseSuit.h BaseRank.cpp BaseRank.h SFMLCard.cpp SFMLCard.h SFMLRank.cpp SFMLRank.h SFMLSuit.cpp SFMLSuit.h Deck.cpp Deck.h CardHand.cpp CardHand.h SuitsColorENUM.h SFMLCardPile.cpp SFMLCardPile.h States.cpp States.h StatesENUM.h SFMLButton.cpp SFMLButton.h RoundedRectangleShape.cpp RoundedRectangleShape.h SFMLMainMenu_Scene.cpp SFMLMainMenu_Scene.h SFMLCardDeckRotating.cpp SFMLCardDeckRotating.h SFMLSceneSwitcher.cpp SFMLSceneSwitcher.h ScenesENUM.h SFMLGamePlaying_Scene.cpp SFMLGamePlaying_Scene.h SceneSwitcher.cpp SceneSwitcher.h CardPile.cpp CardPile.h MouseEvents.cpp MouseEvents.h SFMLCardCornerRS.cpp SFMLCardCornerRS.h FoundationCompassCards.cpp FoundationCompassCards.h CompassENUM.h SFMLCompass.cpp SFMLCompass.h SFMLDeck.cpp SFMLDeck.h SFMLCardOutline.cpp SFMLCardOutline.h BasePlayer.cpp BasePlayer.h SFMLGameTurnOrder.cpp SFMLGameTurnOrder.h SFMLPlayerHand.cpp SFMLPlayerHand.h SFMLSnowFalling.cpp SFMLSnowFalling.h SFMLSpinningKings.cpp SFMLSpinningKings.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()