//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_GAME_H
#define MEMORY_MATCHCARD_GAME_GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;
class Game {
private:
    Deck deck;                      // The deck of cards
    Player player1;                 // Player 1
    Player player2;                 // Player 2
    int currentPlayer;              // Index to track whose turn it is (1 or 2)

public:
    Game();                         // Default constructor
    ~Game();                        // Destructor

    void initializeGame();          // Initialize the game (setup players, shuffle deck, etc.)
    void playTurn();                // Handle a single player's turn
    void displayScores();           // Display current scores
    void start();                   // Start the game loop
};

#endif //MEMORY_MATCHCARD_GAME_GAME_H
