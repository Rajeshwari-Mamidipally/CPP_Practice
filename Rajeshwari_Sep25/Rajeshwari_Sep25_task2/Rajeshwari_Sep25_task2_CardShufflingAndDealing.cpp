#include<iostream>
#include<string>
#include<ctime>
#include "CardShufflingAndDealing.h"
const std::string Card::faces[13] = { //initializing faces[]
    "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
};

const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};//initializing suits[]
Card::Card(int face_,int suit_) //constructor
:
face(face_),
suit(suit_){}

string Card::toString() const { //returning card as a string using toString()
    return faces[face] + " of " + suits[suit];
}
DeckOfCards::DeckOfCards() { //default constructor that initializes the Cards in the deck
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit)); // function push_back to add each Card to the end of the vector after the Card is created and initialized
        }
    }
    currentCard = 0;
}
void DeckOfCards::shuffle() { //shuffles the Cards in the deck
    srand(static_cast<unsigned>(time(0))); // seed random number generator
    for (int i = 0; i < deck.size(); ++i) {
        int randomIndex = rand() % deck.size();
        swap(deck[i], deck[randomIndex]);
    }
    currentCard = 0; // reset current card after shuffle
}
Card DeckOfCards::dealCard() { //returns the next Card object from the deck
    if (moreCards()) {
        return deck[currentCard++];
    } else {
        throw out_of_range("No more cards to deal.");
    }
}
bool DeckOfCards::moreCards() const { //checks whether there are more cards to deal with or not
    return currentCard < deck.size();
}

