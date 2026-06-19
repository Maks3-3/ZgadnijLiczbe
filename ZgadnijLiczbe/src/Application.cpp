#include "Application.h"
#include "SettingsStorage.h"
#include "HallOfFameStorage.h"
#include "WelcomeScreen.h"
#include "SettingsScreen.h"
#include "HallOfFameScreen.h"
#include "GameSetupScreen.h"
#include "GameScreen.h"
#include "Game.h"
#include <memory>
#include <iostream>

Application::Application()
    : settings(SettingsStorage::load()), hallOfFame(HallOfFameStorage::load()) {}

void Application::run() {
    bool running = true;

    while (running) {
        WelcomeScreen welcome(settings.getLanguage(), hallOfFame.getTotalGamesPlayed() > 0);
        MenuChoice choice = welcome.run();

        switch (choice) {
            case MenuChoice::NewGame: {
                GameSetupScreen setup(settings);
                std::unique_ptr<Game> game = setup.run();

                GameScreen gameScreen(settings.getLanguage(), hallOfFame);
                gameScreen.run(std::move(game));

                HallOfFameStorage::save(hallOfFame);
                break;
            }
            case MenuChoice::ShowHallOfFame: {
                HallOfFameScreen hofScreen(hallOfFame, settings.getLanguage());
                hofScreen.run();
                break;
            }
            case MenuChoice::ShowSettings: {
                SettingsScreen settingsScreen(settings, hallOfFame);
                settingsScreen.run();
                break;
            }
            case MenuChoice::Exit:
                running = false;
                break;
        }
    }

    std::cout << "\n" << settings.getLanguage().getText(TextKey::GoodbyeMessage) << "\n";
}
