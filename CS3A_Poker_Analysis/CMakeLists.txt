cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME CS3A_Poker_Analysis)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp BaseCard.cpp BaseCard.h RanksENUM.h SuitsENUM.h BaseSuit.cpp BaseSuit.h BaseRank.cpp BaseRank.h SFMLCard.cpp SFMLCard.h SFMLBackground.cpp SFMLBackground.h SFMLRank.cpp SFMLRank.h SFMLSuit.cpp SFMLSuit.h Deck.cpp Deck.h CardHand.cpp CardHand.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h SuitsColorENUM.h SFMLCardHand.cpp SFMLCardHand.h SFMLDrawHandRank.cpp SFMLDrawHandRank.h ResourceHolder.cpp ResourceHolder.h SFMLDrawAllHandRankings.cpp SFMLDrawAllHandRankings.h)

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