//
// Created by Kiet on 10/09/2023.
//

#ifndef ASSIGNMENT2_GAMESETTINGS_H
#define ASSIGNMENT2_GAMESETTINGS_H
#include "ENUMS.h"
#include "string"
#include "iostream"
#include "player.h"
using namespace std;
class player;
class gameSettings {
private:
    // Mode-specific settings
    int required_companies;
    int required_money;
    int total_days;
    int initial_corporate_powers;
    int initial_money;
    GameMode mode;
public:
    gameSettings(GameMode mode);  // Constructor to initialize based on game mode
    // Getter functions for various settings
    GameMode getGameMode() const;
    void getDetails() const;
    int getRequiredCompanies() const;
    int getRequiredMoney() const;
    int getTotalDays() const;
    int getInitialCorporatePowers() const;
    static int getInitialMoney(GameMode mode);
    static int getInitialCorporatePowers(GameMode mode);
    void initializePlayer(player& p) const;
};


#endif //ASSIGNMENT2_GAMESETTINGS_H
