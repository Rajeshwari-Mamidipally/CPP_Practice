#include <iostream>
#include "Rajeshwari_Sep25_task2_CardShufflingAndDealing.h"
int main() {
    DeckOfCards deck;
    deck.shuffle();

    std::cout << "Dealing all 52 cards:\n\n";

    int count = 0;
    while (deck.moreCards()) {
        std::cout << deck.dealCard().toString() << "\n";
        count++;
    }

    return 0;
}

