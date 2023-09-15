/*******************************************************
  Project: WORKHORSE Functions
   Author: Cheryl Howard
  Purpose: These are permitted reusable functions.
  You are free to include these in your assignments as
  long as you include both comments.
 *******************************************************/

#include "main.h"


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
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t    Risky business:: Share market simulation \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
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
    cout << "Companies to win: " << settings.getRequiredCompanies();
    cout << "\t     Min Money: " << settings.getRequiredMoney();
    cout << "         Day: " << settings.getDay();
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Company's name   \tAvailable   Current \t  Company \t Current \n";
    cout << "                 \t shares      value   \t   cost \t  owner\n";
}
void userProfile(player& Player) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t       " << Player.getName() << "'s Portfolio and Assets" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Total money: " << Player.getMoney();
    cout << "    Companies owned: " << Player.getCompaniesOwned();
    cout << "     Total shares: " << Player.getTotalShare() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void testCompany(){
    char companyChar = 'B';  // Replace with the actual character representing a company
    int cost = Company::getCost(companyChar);  // Call the static getCost function

    if (cost != -1.0) {
        cout << "The cost of the company represented by " << companyChar << " is " << cost << endl;
    } else {
        cout << "Company not found." << endl;
    }
}
///Load the companies.txt and generate Random shares
void initialGame(gameSettings& settings){
    vector<Company> companies = Company::readCompaniesFromFile("companies.txt", settings.getGameMode(), settings);
    Company::generateTotalShares();

}
void displayCompany(){
    int index = 1;  // Initialize index counter
    for (const auto& company : Company::allCompanies) {
        cout << index << ".";  // Print the index
        company.display();
        ++index;  // Increment the index
    }
}
void displayCompanyNameAndCost() {
    for (const auto& company : Company::allCompanies) {  // Assuming allCompanies is a static member of Company
        char shortcut = ' ';
        if (company.getName().size() >= 2) {
            shortcut = company.getName()[1];
        }
        int cost = Company::getCost(shortcut);  // Get the cost using the shortcut character
        string owner = company.getOwner();
        cout
        << company.getName() <<"      "<< company.totalShares <<"          "
        << company.currentValues <<"            "<< cost <<"            "
        << owner << endl;


    }
}

void displayRisks() {
    vector<Risk> risks = Risk::readRisksFromFile("risksAdvanced.txt");
    int index = 1;  // Initialize index counter
    for (const auto& risk : risks) {
        cout << index << ". ";  // Print the index
        risk.getDetail();
        ++index;  // Increment the index
    }
}
// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    player Player("Alice", GameMode::Hard, 1000, 2, 50, 5);
    gameSettings settings(Player.getGameMode());
    settings.initializePlayer(Player);
    initialGame(settings);
    Player.addCompany('A');
    Player.addCompany('B');
    displayTitle();
    gameInterface(settings);
    displayCompanyNameAndCost();
    userProfile(Player);
    Player.viewPlayerOwnedCompanies();
    return 0;
}