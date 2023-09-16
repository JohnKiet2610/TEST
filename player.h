#ifndef ASSIGNMENT2_PLAYER_H
#define ASSIGNMENT2_PLAYER_H
#include <map>
#include "iostream"
#include <string>
#include <vector>
#include "ENUMS.h"        // Include the Enum header for GameMode
#include "gameSettings.h" // Include the GameSettings header
#include "Companies.h"
using namespace std;
class gameSettings;
class Company;
class player {
private:
    // Private Attributes
    string name;
    gameSettings* settings;
    int money;
    int total_shares_owned;
    int total_companies_owned;
    int power_uses_left;
    vector<Company> companiesOwned;
public:
    /// Constructors
    player(string name = "DefaultPlayer", GameMode mode = GameMode::Easy);
    player(string name, GameMode mode, int initialMoney, int initialCompaniesOwned, int initialTotalShares, int initialPowerUsesLeft);
    /// Destructor
    ~player() = default;
    /// Accessor Functions
    string getName() const;
    GameMode getMode() const;
    int getCompaniesOwned() const;
    int getTotalShare() const;
    int getMoney() const;
    GameMode getGameMode() const;
    /// Mutator Functions
    void setMoney(int money);
    void setPowerUsesLeft(int power);
    /// Other Functions
    void addCompany(char shortcut);
    void TakeRisk();
    bool checkForWin() const;
    void viewPlayerOwnedCompanies();
    void getDetails() const;
};



#endif //ASSIGNMENT2_PLAYER_H
