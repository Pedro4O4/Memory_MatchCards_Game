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

    Player(string Pname, int s);

    ~Player();

    void setName(string playerName);
    void setScore(int s);


    string getName() ;
    int getScore() ;


    void displayScore() ;
    void addScore(int points);
    void deduceScore(int points);
};




#endif //MEMORY_MATCHCARD_GAME_PLAYER_H
