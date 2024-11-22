//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_DECK_H
#define MEMORY_MATCHCARD_GAME_DECK_H
#include "Card.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class Deck{
private:
    Card*** grid;
    Card** deck;

public:
    Deck();
    ~Deck();

    void addCard(Card* card);
    void shuffle();
    void displayGrid();
    void flipCard(int row, int col, bool faceUp);
    Card* getCard(int row, int col);
};

#endif //MEMORY_MATCHCARD_GAME_DECK_H
