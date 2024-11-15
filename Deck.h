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

    Card* deck;
    Card **grid;

public:
    Deck();
    ~Deck();

};

#endif //MEMORY_MATCHCARD_GAME_DECK_H
