#include "Companies.h"
// Default Constructor
Company::Company() : rank(0), name(""), power(""), owner("None"), cost(0) {}
// Overloaded Constructor
Company::Company(int rank, const string& name, const string& power, const string& owner, int cost)
        : rank(rank), name(name), power(power), owner(owner), cost(cost) {}
// List
vector<char> Company::companyShortcutList;
vector<Company> Company::allCompanies;
// Getter Functions
int Company::getRank() const {
    return rank;
}
const string& Company::getName() const {
    return name;
}
const string& Company::getPower() const {
    return power;
}
const string& Company::getOwner() const {
    if (owner.empty() || owner == "None") {
        static const string noOwner = "-----";
        return noOwner;
    }
    return owner;
}
// Setter Functions
void Company::setRank(int rank) {
    this->rank = rank;
}
void Company::setName(const string& name) {
    this->name = name;
}
void Company::setPower(const string& power) {
    this->power = power;
}
void Company::setOwner(const string& newOwner) {
    owner = newOwner;
}
void Company::setCost(int cost) {
    this->cost = cost;
}
void Company::display() const {
    char shortcut = ' ';  // Initialize to a space
    if (name.size() >= 2) {  // Make sure the name has at least 2 characters
        shortcut = name[1];  // Get the second character
    }
    cout << "Rank: " << getLevel() << ", Shortcut:" << shortcut << ", Name:" << name << endl <<"Power:" << power <<", Owner: " << getOwner() << "\n";
}
/// Read Company file
vector<Company> Company::readCompaniesFromFile(const string& filename, GameMode mode, gameSettings& settings) {
    vector<Company> companies;
    ifstream file(filename);
    string line;
    int maxCompanies = settings.getMaxCompanies(mode);
    for (int i = 0; i < maxCompanies && getline(file, line); ++i) {
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
    return companies;
}
///Company Index
void Company::companyShortcut(vector<Company> companies) {
    for (const auto& company : companies) {
        if (company.getName().size() >= 2) {  // Make sure the name has at least 2 characters
            char shortcut = company.getName()[1];  // Get the second character
            companyShortcutList.push_back(shortcut);  // Append to the list
        }
    }
}
///Company cost
int Company::getCost(char companyChar) {
    // Assuming companyShortcutList and allCompanies are populated
    for (size_t i = 0; i < Company::companyShortcutList.size(); ++i) {
        if (Company::companyShortcutList[i] == companyChar) {
            return Company::allCompanies[i].cost;  // Directly access the 'cost' member variable
        }
    }
    return -1;  // Return -1 if the company is not found
}
///Company level (Bronze, Silver, Gold)
string Company::getLevel() const {
    if (rank == 1) return "Bronze";
    else if (rank == 2) return "Silver";
    else if (rank == 3) return "Gold";
    else return "Unknown";
}
///Get total shares
void Company::generateTotalShares() {
    for (auto& company : Company::allCompanies) {
        company.totalShares = rand() % 21 + 50;  // Random number between 50 and 70
        company.currentValues = rand() % 4 + 3;  // Random number between 3 and 6
    }
}
///Get detail
void Company::getDetails() const {
    cout << "Company Details:" << endl;
    cout << "Rank: " << rank << endl;
    cout << "Name: " << name << endl;
    cout << "Power: " << power << endl;
    cout << "Owner: " << owner << endl;
    cout << "Cost: " << cost << endl;
}