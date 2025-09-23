#include<string>
#include <ctime>
#include <array>
class CrapsGame{
    public:
    CrapsGame();
    void simulateGames(int totalGames);
    private:
    int rollDice();
    void playSingleGame(int& rollCount, bool& winStatus);
    static const int MAX_ROLLS_TRACKED = 20;
    std::array<int, MAX_ROLLS_TRACKED + 1> winsPerRoll;
    std::array<int, MAX_ROLLS_TRACKED + 1> lossesPerRoll;

    int totalWins;
    int totalLosses;
    int totalRolls;



};
