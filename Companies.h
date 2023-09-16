#ifndef COMPANIES_H
#define COMPANIES_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "gameSettings.h"

using namespace std;

class gameSettings;

class Company {
public:
    // Public variables
    int totalShares;
    int currentValues;
    // Constructors
    Company();
    Company(int rank, const string& name, const string& power, const string& owner = "None", int cost = 0);
    /// Destructor
    ~Company() = default;

    // Getter Functions
    int getRank() const;
    const string& getName() const;
    const string& getPower() const;
    const string& getOwner() const;
    string getLevel() const;
    static int getCost(char companyChar);

    // Setter Functions
    void setRank(int rank);
    void setName(const string& name);
    void setPower(const string& power);
    void setOwner(const string& owner);
    void setCost(int cost);

    // Other Member Functions
    void display() const;
    static vector<Company> readCompaniesFromFile(const string& filename, GameMode mode, gameSettings& settings);
    static void companyShortcut(vector<Company> companies);
    static void generateTotalShares();
    void getDetails() const;

    // Static Variables
    static vector<char> companyShortcutList;
    static vector<Company> allCompanies;

private:
    // Member Variables
    int rank;
    string name;
    string power;
    string owner;
    int cost;

};

#endif //COMPANIES_H