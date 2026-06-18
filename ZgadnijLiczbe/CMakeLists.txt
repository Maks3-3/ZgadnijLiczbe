cmake_minimum_required(VERSION 3.10)
project(ZgadnijLiczbe CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(include)

set(SOURCES
    src/main.cpp
    src/PolishLanguage.cpp
    src/EnglishLanguage.cpp
    src/LanguageFactory.cpp
    src/DifficultyLevel.cpp
    src/RandomGenerator.cpp
    src/Timer.cpp
    src/InputHelper.cpp
    src/ScoreEntry.cpp
    src/HallOfFame.cpp
    src/HallOfFameStorage.cpp
    src/Settings.cpp
    src/SettingsStorage.cpp
    src/Game.cpp
    src/StandardGame.cpp
    src/NewGamePlusGame.cpp
    src/WelcomeScreen.cpp
    src/SettingsScreen.cpp
    src/HallOfFameScreen.cpp
    src/GameSetupScreen.cpp
    src/GameScreen.cpp
    src/Application.cpp
)

add_executable(ZgadnijLiczbe ${SOURCES})
