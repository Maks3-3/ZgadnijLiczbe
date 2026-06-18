#include "PolishLanguage.h"
#include "RandomGenerator.h"
#include <vector>

LanguageCode PolishLanguage::getCode() const {
    return LanguageCode::PL;
}

std::string PolishLanguage::getText(TextKey key) const {
    switch (key) {
        // Ekran powitalny
        case TextKey::WelcomeTitle: return "Zgadnij liczbe";
        case TextKey::MenuNewGame: return "Nowa gra";
        case TextKey::MenuHallOfFame: return "Hall of Fame (TOP5)";
        case TextKey::MenuSettings: return "Ustawienia";
        case TextKey::MenuExit: return "Wyjscie";

        // Ogolne
        case TextKey::InvalidInput: return "Nieprawidlowa wartosc, sprobuj ponownie.";
        case TextKey::InvalidNameMessage: return "Imie nie moze byc puste, sprobuj ponownie.";
        case TextKey::ChoicePrompt: return "Twoj wybor: ";
        case TextKey::PressEnterPrompt: return "Nacisnij Enter, aby kontynuowac...";
        case TextKey::GoodbyeMessage: return "Dziekujemy za gre. Do zobaczenia!";
        case TextKey::YesOption: return "Tak";
        case TextKey::NoOption: return "Nie";
        case TextKey::OnLabel: return "wlaczone";
        case TextKey::OffLabel: return "wylaczone";
        case TextKey::BackOption: return "Powrot do menu";

        // Ustawienia
        case TextKey::SettingsTitle: return "Ustawienia";
        case TextKey::SettingsCurrentLanguageLabel: return "Aktualny jezyk: ";
        case TextKey::SettingsCurrentAskBetLabel: return "Pytanie o tryb zakladu: ";
        case TextKey::SettingsOptionChangeLanguage: return "Zmien jezyk";
        case TextKey::SettingsOptionToggleAskBet: return "Przelacz pytanie o tryb zakladu";
        case TextKey::SettingsOptionClearHallOfFame: return "Wyczysc liste rekordow (Hall of Fame)";
        case TextKey::SettingsChooseLanguagePrompt: return "Wybierz jezyk:";
        case TextKey::SettingsLanguagePLOption: return "Polski";
        case TextKey::SettingsLanguageENOption: return "English";
        case TextKey::SettingsLanguageChanged: return "Jezyk zostal zmieniony.";
        case TextKey::SettingsAskBetToggled: return "Ustawienie zostalo zmienione.";
        case TextKey::SettingsClearConfirmPrompt:
            return "Czy na pewno chcesz wyczyscic liste rekordow? Tej operacji nie da sie odwrocic.";
        case TextKey::SettingsCleared: return "Lista rekordow zostala wyczyszczona.";
        case TextKey::SettingsClearCancelled: return "Czyszczenie zostalo odwolane.";

        // Konfiguracja nowej gry
        case TextKey::SetupChooseModeTitle: return "Wybierz tryb gry:";
        case TextKey::SetupModeStandardOption: return "Zgadnij liczbe (standard)";
        case TextKey::SetupModeNewGamePlusOption: return "Nowa gra plus";
        case TextKey::SetupChooseDifficultyTitle: return "Wybierz poziom trudnosci:";
        case TextKey::DifficultyEasyLabel: return "Latwy";
        case TextKey::DifficultyMediumLabel: return "Sredni";
        case TextKey::DifficultyHardLabel: return "Trudny";
        case TextKey::SetupAskBetModePrompt: return "Czy chcesz wlaczyc tryb zakladu?";
        case TextKey::SetupAskMaxAttemptsPrompt: return "Podaj maksymalna liczbe prob: ";

        // W trakcie gry
        case TextKey::AttemptLabel: return "Proba nr: ";
        case TextKey::GuessPrompt: return "Podaj swoja liczbe: ";
        case TextKey::CorrectGuessMessage: return "Brawo! Zgadnales poprawna liczbe!";
        case TextKey::EnterNamePrompt: return "Podaj swoje imie: ";
        case TextKey::NewGamePlusRerollMessage:
            return ">>> Liczba zostala wylosowana na nowo! Liczba prob liczy sie dalej. <<<";
        case TextKey::WonAttemptsLabel: return "Liczba prob: ";
        case TextKey::WonTimeLabel: return "Czas rozgrywki (s): ";
        case TextKey::EnteredHallOfFameMessage: return "Gratulacje! Twoj wynik trafil do Hall of Fame!";
        case TextKey::LostBetMessage:
            return "Koniec gry - przekroczono maksymalna liczbe prob. Szukana liczba to: ";

        // Hall of Fame
        case TextKey::HallOfFameTitle: return "Hall of Fame";
        case TextKey::HallOfFameEmptyMessage: return "Brak zapisanych wynikow dla tego poziomu trudnosci.";
        case TextKey::HallOfFameHeaderRank: return "Miejsce";
        case TextKey::HallOfFameHeaderName: return "Imie";
        case TextKey::HallOfFameHeaderAttempts: return "Proby";
        case TextKey::HallOfFameHeaderTime: return "Czas (s)";
        case TextKey::HallOfFameNewGamePlusTag: return "[Nowa gra plus]";
        case TextKey::HallOfFameSwitchOption: return "Przelacz poziom trudnosci";
        case TextKey::CurrentDifficultyLabel: return "Poziom trudnosci: ";
    }
    return "";
}

std::string PolishLanguage::getRandomTooLowMessage() const {
    static const std::vector<std::string> messages = {
        "Za malo! Strzelaj wyzej.",
        "Nie, szukana liczba jest wieksza.",
        "Zgadnij wyżej.",
        "Twoja liczba jest za mala.",
        "Wyzej!",
        "To jeszcze nie to, szukana liczba jest wieksza."
    };
    return messages[RandomGenerator::nextInt(0, static_cast<int>(messages.size()) - 1)];
}

std::string PolishLanguage::getRandomTooHighMessage() const {
    static const std::vector<std::string> messages = {
        "Za duzo! Strzelaj nizej.",
        "Nie, szukana liczba jest mniejsza.",
        "Liczba jest mniejsza.",
        "Twoja liczba jest za duza.",
        "Nizej nizej!",
        "To jeszcze nie to, szukana liczba jest mniejsza."
    };
    return messages[RandomGenerator::nextInt(0, static_cast<int>(messages.size()) - 1)];
}
