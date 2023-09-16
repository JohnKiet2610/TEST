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
    cout << "\t            Risky business:: Share market simulation \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
char askForLetter(string question) {
    // ask a single letter response question
    char userInput = ' ';
    while (!isalpha(userInput)) {
        cout << "\n " + question;
        cin >> userInput;
    }
    cin.ignore();
    return toupper(userInput);
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
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void gameInterface(gameSettings& settings) {
    cout << "Companies to win: " << settings.getRequiredCompanies();
    cout << "\t          Min Money: " << settings.getRequiredMoney();
    cout << "                      Day: " << settings.getDay();
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Company's name   \tAvailable   Current \t  Company \t Current \n";
    cout << "                 \t shares      value   \t   cost \t  owner\n";
}
void userProfile(player& Player) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t       " << Player.getName() << "'s Portfolio and Assets\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Total money: " << Player.getMoney();
    cout << "    Companies owned: " << Player.getCompaniesOwned();
    cout << "     Total shares: " << Player.getTotalShare() << "\n\n";
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
// ------------ Gameplay Logic Functions ---------------
void playerAction(){
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t [B]uy   [S]ell    [A]cquire    [P]ower    [R]isk    [Q]uit                   \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    char Choice = askForLetter("What will you do now? ");
    switch (Choice) {
        case 'B':
            cout << "Buy will be implemented.\n";
            break;
        case 'S':
            cout << "Sell will be implemented.\n";
            break;
        case 'A':
            cout << "Acquire will be implemented.\n";
            break;
        case 'P':
            cout << "Power use will be implemented.\n";
            break;
        case 'R':
            cout << "Risk will be implemented.\n";
            break;
        case 'Q':
            cout << "Quitting the game.\n";
            exit(0); // End the game
        default:
            cout << "Invalid option.\n";
            break;
    }
}
///Load the companies.txt and generate Random shares
void initialGame(gameSettings& settings){
    vector<Company> companies = Company::readCompaniesFromFile("companies.txt", settings.getGameMode(), settings);
    Company::generateTotalShares();

}
// ------------ Main Function ---------------
int main() {
    srand(static_cast<unsigned int>(time(0)));
    /// Testing constructor, initialize all needed function to make the game work
    player defaultPlayer;
    player Player("Alice", GameMode::Hard, 1000, 2, 50, 5);
    gameSettings settings(defaultPlayer.getGameMode());
    settings.initializePlayer(defaultPlayer);
    initialGame(settings);

    /// Testing add companies to player
    defaultPlayer.addCompany('A');
    defaultPlayer.addCompany('B');
    ///Display all the risks
    //displayRisks();
    ///Display Companies
    //displayCompany();
    /// Intro game
    displayTextFile("RBintro.txt");
    /// Game UI
    displayTitle();
    gameInterface(settings);
    displayCompanyNameAndCost();
    userProfile(defaultPlayer);
    defaultPlayer.viewPlayerOwnedCompanies();
    playerAction();

    return 0;
}