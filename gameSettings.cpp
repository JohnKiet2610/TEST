
#include "gameSettings.h"
gameSettings::gameSettings(GameMode mode): mode(mode) {
    switch (mode) {
        case Easy:
            initial_money = 1000;
            required_companies = 3;
            required_money = 500;
            total_days = 40;
            initial_corporate_powers = 6;
            break;
        case Tricky:
            initial_money = 900;
            required_companies = 4;
            required_money = 600;
            total_days = 50;
            initial_corporate_powers = 5;
            break;
        case Hard:
            initial_money = 800;
            required_companies = 5;
            required_money = 700;
            total_days = 60;
            initial_corporate_powers = 4;
            break;
    }
}
int gameSettings::getInitialMoney(GameMode mode) {
    switch (mode) {
        case Easy:
            return 1000;
        case Tricky:
            return 900;
        case Hard:
            return 800;
        default:
            return 0;
    }
}

int gameSettings::getInitialCorporatePowers(GameMode mode) {
    switch (mode) {
        case Easy:
            return 6;
        case Tricky:
            return 5;
        case Hard:
            return 4;
        default:
            return 0;
    }
}
int gameSettings::getRequiredCompanies() const {
    return required_companies;
}
int gameSettings::getRequiredMoney() const {
    return required_money;
}
int gameSettings::getTotalDays() const {
    return total_days;
}
int gameSettings::getInitialCorporatePowers() const {
    return initial_corporate_powers;
}
void gameSettings::initializePlayer(player& p) const {
    GameMode mode = p.getGameMode();
    p.setMoney(getInitialMoney(mode));
    p.setPowerUsesLeft(getInitialCorporatePowers(mode));
}
GameMode gameSettings::getGameMode() const {
    return mode;
}
void gameSettings::getDetails() const {
    cout << "Required Companies to Win: " << getRequiredCompanies() << endl;
    cout << "Required Money to Win: " << getRequiredMoney() << endl;
    cout << "Total Days to Play: " << getTotalDays() << endl;  // assuming you have a method to get this
}