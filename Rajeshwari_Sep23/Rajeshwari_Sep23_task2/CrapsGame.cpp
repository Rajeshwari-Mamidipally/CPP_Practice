#include<iostream>
#include "CrapsGame.h"
CrapsGame::CrapsGame()
:
totalWins(0),
totalLosses(0),
totalRolls(0)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    winsPerRoll.fill(0);
    lossesPerRoll.fill(0);
}
int CrapsGame::rollDice()// roll dice, calculate sum and display results
{
// pick random die values
int die1 = 1 + rand() % 6; // first die roll
int die2 = 1 + rand() % 6; // second die roll 
int sum = die1 + die2; // compute sum of die values
// display results of this roll
std::cout << "Player rolled " << die1 << " + " << die2<< " = " << sum <<std::endl;
return sum;
} 

// Play a single game of craps
void CrapsGame::playSingleGame(int& rollCount, bool& winStatus) {
    enum Status { CONTINUE, WON, LOST };
    Status gameStatus;

    int myPoint = 0;
    int sumOfDice = rollDice();
    rollCount = 1;

    // First roll
    switch (sumOfDice) {
        case 7: case 11:
            gameStatus = WON;
            break;
        case 2: case 3: case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
    }

    // Continue rolling until win or loss
    while (gameStatus == CONTINUE) {
        sumOfDice = rollDice();
        ++rollCount;

        if (sumOfDice == myPoint)
            gameStatus = WON;
        else if (sumOfDice == 7)
            gameStatus = LOST;
    }

    // Return results
    winStatus = (gameStatus == WON);
}
// Simulate multiple games
void CrapsGame::simulateGames(int totalGames) {
    for (int i = 0; i < totalGames; ++i) {
        int rollCount = 0;
        bool winStatus = false;

        playSingleGame(rollCount, winStatus);
        totalRolls += rollCount;

        // Track roll position
        int index = (rollCount <= MAX_ROLLS_TRACKED) ? rollCount - 1 : MAX_ROLLS_TRACKED;

        if (winStatus) {
            ++totalWins;
            ++winsPerRoll[index];
        } else {
            ++totalLosses;
            ++lossesPerRoll[index];
        }
    }

    // Display results
    std::cout << "===== Craps Simulation Results =====" << std::endl;
    std::cout << "Total games simulated: " << totalGames << "\n" << std::endl;
    // a) Games won by roll
    std::cout << "Wins by roll:" << std::endl;
    for (int i = 0; i < MAX_ROLLS_TRACKED; ++i) {
        std::cout << "Roll " << i + 1 << ": " << winsPerRoll[i] << std::endl;
    }
    std::cout << "After 20 rolls: " << winsPerRoll[MAX_ROLLS_TRACKED] << "\n" << std::endl;

    // b) Games lost by roll
    std::cout << "Losses by roll:" << std::endl;
    for (int i = 0; i < MAX_ROLLS_TRACKED; ++i) {
        std::cout << "Roll " << i + 1 << ": " << lossesPerRoll[i] << std::endl;
    }
    std::cout << "After 20 rolls: " << lossesPerRoll[MAX_ROLLS_TRACKED] << "\n" << std::endl;

    // c) Chance of winning
    double winChance = static_cast<double>(totalWins) / totalGames * 100.0;
    std::cout << "Chance of winning: " << winChance << "%\n" << std::endl;

    // d) Average game length
    double avgLength = static_cast<double>(totalRolls) / totalGames;
    std::cout << "Average game length (rolls): " << avgLength << "\n" << std::endl;

    // e) Does game length affect win probability?
    std::cout << "Observation: Craps is a fair game because the win probability is close to 50%, "<< "but slightly favors the house (~49.3% win rate).\n";
    std::cout << "Longer games don't necessarily improve winning chances.\n";
}
