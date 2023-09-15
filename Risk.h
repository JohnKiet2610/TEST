//
// Created by Kiet on 14/09/2023.
//

#ifndef ASSIGNMENT2_2_RISK_H
#define ASSIGNMENT2_2_RISK_H
using namespace std;
#include "Companies.h"
#include "player.h"
#include "gameSettings.h"
class Risk {
public:
    Risk();
    Risk(const string& name, const string& attribute, int minValue, int maxValue);

    // Getters
    const string& getName() const;
    const string& getAttribute() const;
    int getMinValue() const;
    int getMaxValue() const;
    static vector<Risk> readRisksFromFile(const string& filename);
    void getDetail() const;

private:
    string name;
    string affectedPlayers;
    string attribute;
    int minValue;
    int maxValue;
};


#endif //ASSIGNMENT2_2_RISK_H
