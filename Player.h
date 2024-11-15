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
    Player(string name,int score);
    ~Player();
    string getName();
    void setName();
    int getScore();
    void setScore();
    void displayScore();
};



#endif //MEMORY_MATCHCARD_GAME_PLAYER_H
