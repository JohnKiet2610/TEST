
#include "iostream"
#include "main.h"
#include <string>
#include <vector>
#include "gameSettings.h" // Include the GameSettings header
#include "player.h"
using namespace std;

void testPlayer() {
    // Create a Player object using the overloaded constructor
    player Player("Alice", GameMode::Tricky, 1000, 2, 50, 5);  // Assuming 'Tricky' is one of the GameMode enum values

    // Print attributes to check if they have been initialized correctly
    gameSettings settings(Player.getGameMode());
    settings.initializePlayer(Player);
    Player.getDetails();
    cout << endl;
    settings.getDetails();
}

// Main function
int main() {
    // Call the testPlayer function to test the Player class
    testPlayer();

    return 0;
}