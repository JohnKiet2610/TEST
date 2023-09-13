//
// Created by Kiet on 12/09/2023.
//

#include "Companies.h"
Company::Company() : rank(0), name(""), power("") {}

Company::Company(int rank, const string& name, const string& power, const string& owner, int cost)
        : rank(rank), name(name), power(power), owner(owner), cost(cost) {}
int Company::getRank() const {
    return rank;
}
const string& Company::getName() const {
    return name;
}
const string& Company::getPower() const {
    return power;
}
const string& Company::getOwner() const {  // New getter for owner
    return owner;
}

void Company::display() const {
    cout << "Rank: " << rank << ", Name: " << name << ", Power: " << power << ", Owner: " << owner << endl;
}
vector<Company> Company::allCompanies;
vector<Company> Company::readCompaniesFromFile(const string& filename, GameMode mode, gameSettings& settings) {
    vector<Company> companies;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string rank_str, name, power;
        getline(ss, rank_str, ';');
        getline(ss, name, ';');
        getline(ss, power, ';');
        int rank = stoi(rank_str);
        int cost = 0;  // Initialize cost
        if (rank == 1) cost = 30;  // Bronze
        else if (rank == 2) cost = 40;  // Silver
        else if (rank == 3) cost = 50;  // Gold
        companies.push_back(Company(rank, name, power, "None", cost));  // Initialize with cost
    }
    Company::allCompanies = companies;

    // Populate companyShortcutList after reading all companies
    Company::companyShortcut(companies);

    // Debugging: Print out the first few companies for verification
    for (int i = 0; i < settings.getMaxCompanies(mode); i++) {
        cout << companies[i].getName() << endl;
    }

    return companies;
}
vector<char> Company::companyShortcutList;
void Company::companyShortcut(vector<Company> companies) {
    for (const auto& company : companies) {
        if (company.getName().size() >= 2) {  // Make sure the name has at least 2 characters
            char shortcut = company.getName()[1];  // Get the second character
            companyShortcutList.push_back(shortcut);  // Append to the list
        }
    }
}
int Company::getCost(char companyChar) {
    // Assuming companyShortcutList and allCompanies are populated
    for (size_t i = 0; i < Company::companyShortcutList.size(); ++i) {
        if (Company::companyShortcutList[i] == companyChar) {
            return Company::allCompanies[i].cost;  // Directly access the 'cost' member variable
        }
    }
    return -1;  // Return -1 if the company is not found
}