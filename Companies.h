//
// Created by Kiet on 12/09/2023.
//

#ifndef COMPANIES_H
#define COMPANIES_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "gameSettings.h"
using namespace std;


class gameSettings;
class Company {
public:
    Company();
    Company(int rank, const string& name, const string& power, const string& owner = "None", int cost = 0);
    int getRank() const;
    const string& getName() const;
    const string& getPower() const;
    const string& getOwner() const;
    static int getCost(char companyChar);
    void display() const;
    static vector<char> companyShortcutList;
    static vector<Company> allCompanies;
    static vector<Company> readCompaniesFromFile(const string& filename, GameMode mode, gameSettings& settings);
    static void companyShortcut(vector<Company> companies);

private:
    int rank;
    string name;
    string power;
    string owner;
    int cost;
};


#endif //COMPANIES_H
