//
// Created by amh24 on 14/11/2024.
//

#ifndef MEMORY_MATCHCARD_GAME_BONUSCARD_H
#define MEMORY_MATCHCARD_GAME_BONUSCARD_H
#include <bits/stdc++.h>
#include "Card.h"
using namespace std;
class BonusCard:Card{
private:
    int bonusPoints;
public:

    BonusCard();
    BonusCard(int bonusPoints);
    ~BonusCard();
    void display();




};



#endif //MEMORY_MATCHCARD_GAME_BONUSCARD_H
