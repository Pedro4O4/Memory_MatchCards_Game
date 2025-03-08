//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_GAME_H
#define MEMORY_MATCHCARD_GAME_GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;
/*class Game {
public:
    Deck deck;                      // The deck of cards
    Player player1;                 // Player 1
    Player player2;                 // Player 2
    int currentPlayer;              // Index to track whose turn it is (1 or 2)
    Game();                         // Default constructor
    ~Game();                        // Destructor

    void initializeGame();          // Initialize the game (setup players, shuffle deck, etc.)
    void playTurn();                // Handle a single player's turn
    void displayScores();           // Display current scores
    void start();                   // Start the game loop
};
*/
// Game.h
class Game {
public:
    Game();  // Add this constructor declaration
    ~Game();
    void initializeGame();
    void playTurn();
    void displayScores();
    void start();

    void displayPlayerInfo();

    void playTwice();

    void scoring();

private:
    Deck deck;
    Player player1;
    Player player2;
    int currentPlayer = 1;
};


#endif //MEMORY_MATCHCARD_GAME_GAME_H
