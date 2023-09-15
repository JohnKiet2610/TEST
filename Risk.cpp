//
// Created by Kiet on 14/09/2023.
//

#include "Risk.h"

// Constructor implementations
Risk::Risk() : name(""), affectedPlayers(""), attribute(""), minValue(0), maxValue(0) {}
Risk::Risk(const string& name, const string& attribute, int minValue, int maxValue) : name(name), affectedPlayers(affectedPlayers), attribute(attribute), minValue(minValue), maxValue(maxValue) {}

// Function to read risks from a file
vector<Risk> Risk::readRisksFromFile(const string& filename) {
    vector<Risk> risks;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, affectedPlayers, attribute, min_str, max_str;
        getline(ss, name, ';');
        getline(ss, attribute, ';');
        getline(ss, min_str, ';');
        getline(ss, max_str, ';');

        istringstream iss_min(min_str);
        istringstream iss_max(max_str);
        int minValue, maxValue;
        iss_min >> minValue;
        iss_max >> maxValue;

        risks.push_back(Risk(name, attribute, minValue, maxValue));
    }
    return risks;
}
void Risk::getDetail() const {
    cout << "Name: " << name << ", Attribute: " << attribute << ", Min Value: " << minValue << ", Max Value: " << maxValue << endl;
}