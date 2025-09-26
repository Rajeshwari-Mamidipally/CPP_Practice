#ifndef CARDSHUFFLINGANDDEALING_H
#define CARDSHUFFLINGANDDEALING_H
#include <string>
#include<vector>
using namespace std;
class Card {
private:
    int face;  
    int suit;  

public:
    // Static arrays
    static const string faces[13];
    static const string suits[4];
    
    Card(int, int);// Constructor
    string toString() const; // Returns card as a string: "Face of Suit"
};
class DeckOfCards{
    private:
    vector<Card> deck;   // vector to store 52 cards
    int currentCard;      // index of next card to deal
    public:
    DeckOfCards();        // Constructor to create and initialize the deck
    void shuffle();       // Shuffle the deck
    Card dealCard();      // Deal the next card
    bool moreCards() const; // Check if more cards are available

};

#endif