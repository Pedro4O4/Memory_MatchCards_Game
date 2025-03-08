
#ifndef MEMORY_MATCHCARD_GAME_PENALTYCARD_H
#define MEMORY_MATCHCARD_GAME_PENALTYCARD_H
#include <bits/stdc++.h>
#include "Card.h"
#include "Player.h"

using namespace std;
class PenaltyCard:public Card{

private:
    int  penaltyPoints ;
public:
    PenaltyCard();
    PenaltyCard( int value , bool isFaceUp ,int penaltyPoints);

    ~PenaltyCard();

    void setPenaltyPoints(int points);
    int getPenaltyPoints();

   virtual  void display();


    int getPenaltyPoints() const { return penaltyPoints; }




};
#endif
