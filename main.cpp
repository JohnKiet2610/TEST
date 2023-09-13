/*******************************************************
  Project: WORKHORSE Functions
   Author: Cheryl Howard
  Purpose: These are permitted reusable functions.
  You are free to include these in your assignments as
  long as you include both comments.
 *******************************************************/
#include "iostream"
#include "main.h"
#include <string>
#include <fstream>
#include <vector>
#include "gameSettings.h" // Include the GameSettings header
#include "player.h"
#include "Companies.h"
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// you MUST include: waitForPlayer() and clearScreen()
void waitForPlayer() {
    system("pause");
}
void clearScreen() {
    // Windows
    system("cls");
}
void displayTitle() {
    // use this if NOT using the title as a constant
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t    Risky business\n";
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void testPlayer() {
    // Create a Player object using the overloaded constructor
    player Player("Alice", GameMode::Tricky, 1000, 2, 50, 5);

    // Print attributes to check if they have been initialized correctly
    gameSettings settings(Player.getGameMode());
    settings.initializePlayer(Player);
}
void displayTextFile(string myFile) {
    // local vars
    ifstream blurbData(myFile);
    string line = "";
    // read in file data
    if (blurbData.is_open()) {
        while (getline(blurbData, line)) {
            cout << line << "\n" ;
        }
    }
    blurbData.close();
    waitForPlayer();
    clearScreen();
}
void gameInterface(gameSettings& settings) {
    cout <<"Companies to win: "<<settings.getRequiredCompanies() <<"\t  Min Money: "<< settings.getRequiredMoney() <<endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
void userProfile(player& Player) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "           " << Player.getName() << "'s Portfolio and Assets" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Total money: " << Player.getMoney();
    cout << "    Companies owned: " << Player.getCompaniesOwned();
    cout << "     Total shares: " << Player.getTotalShare() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void testCompany(){
    char companyChar = 'B';  // Replace with the actual character representing a company
    int cost = Company::getCost(companyChar);  // Call the static getCost function

    if (cost != -1.0) {
        std::cout << "The cost of the company represented by " << companyChar << " is " << cost << std::endl;
    } else {
        std::cout << "Company not found." << std::endl;
    }
}
void displayCompany(gameSettings& settings){

    vector<Company> companies = Company::readCompaniesFromFile("companies.txt", settings.getGameMode(), settings);
}
// Main function
int main() {
    player Player("Alice", GameMode::Hard, 1000, 2, 50, 5);


    gameSettings settings(Player.getGameMode());
    settings.initializePlayer(Player);


    displayTextFile("RBintro.txt");
    clearScreen();
    displayTitle();
    gameInterface(settings);
    displayCompany(settings);
    userProfile(Player);
    waitForPlayer();
    Player.addCompany('A');
    waitForPlayer();
    Player.viewPlayerOwnedCompanies();
    waitForPlayer();
    clearScreen();
    testCompany();


    return 0;
}