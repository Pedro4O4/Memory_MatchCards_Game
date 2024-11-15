//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_GAME_H
#define MEMORY_MATCHCARD_GAME_GAME_H
#include "Deck.h"
#include "Player.h"
class Game{
private:
    Deck deck;
    Player player1;
    Player player2;
    int currentTurn;
    bool gameOver;
public:
   void initializeGame();
};

#endif //MEMORY_MATCHCARD_GAME_GAME_H
