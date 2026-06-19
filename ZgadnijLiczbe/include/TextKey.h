#pragma once

// Klucze wszystkich tekstow wyswietlanych w grze.
// Kazdy klucz ma swoje tlumaczenie w PolishLanguage i EnglishLanguage.
enum class TextKey {
    // Ekran powitalny
    WelcomeTitle,
    MenuNewGame,
    MenuHallOfFame,
    MenuSettings,
    MenuExit,

    // Ogolne / wspoldzielone przez wiele ekranow
    InvalidInput,
    InvalidNameMessage,
    ChoicePrompt,
    PressEnterPrompt,
    GoodbyeMessage,
    YesOption,
    NoOption,
    OnLabel,
    OffLabel,
    BackOption,

    // Ekran ustawien
    SettingsTitle,
    SettingsCurrentLanguageLabel,
    SettingsCurrentAskBetLabel,
    SettingsOptionChangeLanguage,
    SettingsOptionToggleAskBet,
    SettingsOptionClearHallOfFame,
    SettingsChooseLanguagePrompt,
    SettingsLanguagePLOption,
    SettingsLanguageENOption,
    SettingsLanguageChanged,
    SettingsAskBetToggled,
    SettingsClearConfirmPrompt,
    SettingsCleared,
    SettingsClearCancelled,

    // Konfiguracja nowej gry (tryb + trudnosc + zaklad)
    SetupChooseModeTitle,
    SetupModeStandardOption,
    SetupModeNewGamePlusOption,
    SetupChooseDifficultyTitle,
    DifficultyEasyLabel,
    DifficultyMediumLabel,
    DifficultyHardLabel,
    SetupAskBetModePrompt,
    SetupAskMaxAttemptsPrompt,

    // W trakcie gry
    AttemptLabel,
    GuessPrompt,
    CorrectGuessMessage,
    EnterNamePrompt,
    NewGamePlusRerollMessage,
    WonAttemptsLabel,
    WonTimeLabel,
    EnteredHallOfFameMessage,
    LostBetMessage,

    // Ekran Hall of Fame
    HallOfFameTitle,
    HallOfFameEmptyMessage,
    HallOfFameHeaderRank,
    HallOfFameHeaderName,
    HallOfFameHeaderAttempts,
    HallOfFameHeaderTime,
    HallOfFameNewGamePlusTag,
    HallOfFameSwitchOption,
    CurrentDifficultyLabel
};
