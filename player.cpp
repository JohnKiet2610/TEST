
#include <sstream>

#include "player.h"
#include "gameSettings.h"

player::player(string name, GameMode mode, int initialMoney, int initialCompaniesOwned, int initialTotalShares, int initialPowerUsesLeft)
        : name(name),
          settings(new gameSettings(mode)),  // Initialize the settings member
          money(initialMoney),
          total_shares_owned(initialTotalShares),
          total_companies_owned(initialCompaniesOwned),
          power_uses_left(initialPowerUsesLeft)
{}
string player::getName() const {
    return name;
}
GameMode player::getMode() const {
    return settings->getGameMode();
}
void player::viewPlayerOwnedCompanies() {
    if (companiesOwned.empty()) {
        cout << "You do not own any companies yet." << endl;
        return;
    }

    cout << "Companies owned by player: " << endl;
    for (const auto& company : companiesOwned) {
        cout << company.getName() << endl;  // Assuming Company has a getName() method
    }
}
int player::getCompaniesOwned() const {
    return total_companies_owned;
}
int player::getTotalShare() const {
    return total_shares_owned;
}
void player::setPowerUsesLeft(int power) {
    this->power_uses_left = power;
}
//void player::addCompany(char shortcut) {
//    auto it = find(Company::companyShortcutList.begin(), Company::companyShortcutList.end(), shortcut);
//    if (it != Company::companyShortcutList.end()) {
//        int index = distance(Company::companyShortcutList.begin(), it);
//        companiesOwned.push_back(Company::allCompanies[index]);
//        cout << "You now own the company " << Company::allCompanies[index].getName() << "." << endl;
//    } else {
//        cout << "Invalid company shortcut." << endl;
//    }
//}
void player::addCompany(char shortcut) {
    auto it = find(Company::companyShortcutList.begin(), Company::companyShortcutList.end(), shortcut);
    if (it != Company::companyShortcutList.end()) {
        int index = distance(Company::companyShortcutList.begin(), it);
        companiesOwned.push_back(Company::allCompanies[index]);

        // Update the owner field of the Company
        Company::allCompanies[index].setOwner(this->name);  // Assuming 'name' is the field containing the player's name

        cout << "You now own the company " << Company::allCompanies[index].getName() << endl;
    } else {
        cout << "Invalid company shortcut." << endl;
    }
}
GameMode player::getGameMode() const {
    return settings->getGameMode();
}
//void player::BuyShares(Company& company, int quantity) {
//    // Implementation here
//}
//
//void player::SellShares(Company& company, int quantity) {
//    // Implementation here
//}
//
//void player::AcquireCompany(Company& company) {
//    // Implementation here
//}
//
//void player::UseCorporatePower(Company& company) {
//    // Implementation here
//}
void player::TakeRisk() {
    // Implementation here
    cout << "You have take a risk";
}
int player::getMoney() const {
    return money;
}
void player::setMoney(int money) {
    this->money = money;
}
void player::getDetails() const {
    cout << "Player Name: " << name << endl;
    cout << "Money: " << money << endl;
    cout << "Companies Owned: " << total_companies_owned << endl;
    cout << "Total Shares: " << total_shares_owned << endl;

}






