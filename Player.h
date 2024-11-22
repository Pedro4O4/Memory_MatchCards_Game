//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_PLAYER_H
#define MEMORY_MATCHCARD_GAME_PLAYER_H
#include <bits/stdc++.h>
using namespace std;
class Player{
private:
    string name;
    int score;

public:

    Player();

    Player(string playerName);

    ~Player();

    void setName(string& playerName);
    void setScore(int playerScore);


    string getName() ;
    int getScore() ;


    void displayScore() ;      // Displays the player's current score
    void addScore(int points);      // Increases the player's score by a specified number of points
    void deductScore(int points);   // Decreases the player's score by a specified number of points
};




#endif //MEMORY_MATCHCARD_GAME_PLAYER_H
