
#include "gameSettings.h"
GameMode gameSettings::getGameMode() const {
    return mode;
}
gameSettings::gameSettings(GameMode mode): mode(mode) {
    switch (mode) {
        case 4: //Easy
            required_companies = 3;
            required_money = 500;
            total_days = 40;
            initial_corporate_powers = 6;
            break;
        case 5: //Tricky
            required_companies = 4;
            required_money = 600;
            total_days = 50;
            initial_corporate_powers = 5;
            break;
        case 6: //Hard
            required_companies = 5;
            required_money = 700;
            total_days = 60;
            initial_corporate_powers = 4;
            break;
    }
}
int gameSettings::getInitialMoney(GameMode mode) {
    switch (mode) {
        case 4: //Easy
            return 1000;
        case 5: //Tricky
            return 900;
        case 6: //Hard
            return 800;
    }
}

int gameSettings::getInitialCorporatePowers(GameMode mode) {
    switch (mode) {
        case 4: //Easy
            return 6;
        case 5: //Tricky
            return 5;
        case 6: //Hard
            return 4;
        default:
            return 0;
    }
}
int gameSettings::getMaxCompanies(GameMode mode) {
    switch (mode) {
        case 4: //Easy
            return 12;
        case 5: //Tricky
            return 15;
        case 6: //Hard
            return 18;
        default:
            return 0;
    }
}
int gameSettings::getRequiredCompanies() const {
    return required_companies;
}
int gameSettings::getDay() const {
    return 1;
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

void gameSettings::getDetails() const {
    cout << "Required Companies to Win: " << getRequiredCompanies() << endl;
    cout << "Required Money to Win: " << getRequiredMoney() << endl;
    cout << "Total Days to Play: " << getTotalDays() << endl;
    cout << "Total Corporate Power can use: "<< getInitialCorporatePowers() << endl;// assuming you have a method to get this
}