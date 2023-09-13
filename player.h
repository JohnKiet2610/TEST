//
// Created by Kiet on 10/09/2023.
//

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
    // Member Variables
    string name;
    gameSettings* settings;
    int money;
    int total_shares_owned;
    int total_companies_owned;
    int power_uses_left;
    vector<Company> companiesOwned;

//vector<Company> company_details;  // Vector to store details of related companies
public:
    // Constructor
    player(string name, GameMode mode);
    player(string name, GameMode mode, int initialMoney, int initialCompaniesOwned, int initialTotalShares, int initialPowerUsesLeft);
    // Member Functions
//    void BuyShares(Company& company, int quantity);
//    void SellShares(Company& company, int quantity);
//    void AcquireCompany(Company& company);
//    void UseCorporatePower(Company& company);
    string getName() const;
    GameMode getMode() const;
    void addCompany(char shortcut);
    int getCompaniesOwned() const;
    int getTotalShare() const;
    void TakeRisk();  // Assuming Risk is another class or structured data
    bool checkForWin() const; // Will move to gameFunction
    // Function to calculate the final score (if time runs out)
    void setMoney(int money);
    void setPowerUsesLeft(int power);
    void viewPlayerOwnedCompanies();
    // Getter and Setter for money (for demonstration)
    int getMoney() const;
    void getDetails() const;
    GameMode getGameMode() const;
};



#endif //ASSIGNMENT2_PLAYER_H
