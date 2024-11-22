//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_DECK_H
#define MEMORY_MATCHCARD_GAME_DECK_H
#include <bits/stdc++.h>
using namespace std;
#include "Card.h"
class Deck{
private:
    Card* deck;            // Dynamically allocated array of cards
    Card* grid[4][4];      // 4x4 grid of card pointers

public:
    // Constructor
    Deck();

    // Destructor
    ~Deck();

    void addCard(Card* card);

    // Shuffle the deck and assign cards to the grid
    void shuffle();

    // Display the current layout of the grid
    void displayGrid();

};

#endif //MEMORY_MATCHCARD_GAME_DECK_H
