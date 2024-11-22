#include <bits/stdc++.h>
using namespace std;

#include "Card.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "Player.h"
#include "Deck.h"
#include "Game.h"
// Card Implementation
Card::Card() : number(0), isFaceUp(false) {}
Card::Card(int num) : number(num), isFaceUp(false) {}
Card::~Card() {}

void Card::setNumber(int num) { number = num; }
void Card::setFaceUp(bool faceUp) { isFaceUp = faceUp; }
int Card::getNumber() { return number; }
bool Card::getFaceUp() { return isFaceUp; }
void Card::display() { cout << (isFaceUp ? to_string(number) : "*"); }

// BonusCard Implementation
BonusCard::BonusCard() : Card(), bonusPoints(0) {}
BonusCard::BonusCard(int num, int points) : Card(num), bonusPoints(points) {}
BonusCard::~BonusCard() {}
void BonusCard::setBonusPoints(int points) { bonusPoints = points; }
int BonusCard::getBonusPoints() { return bonusPoints; }
void BonusCard::display() {
    if (getFaceUp()) {
        cout << getNumber() << " (Bonus: +" << bonusPoints << ")";
    } else {
        cout << "*";
    }
}

// PenaltyCard Implementation
PenaltyCard::PenaltyCard() : Card(), penaltyPoints(0) {}
PenaltyCard::PenaltyCard(int num, int points) : Card(num), penaltyPoints(points) {}
PenaltyCard::~PenaltyCard() {}
void PenaltyCard::setPenaltyPoints(int points) { penaltyPoints = points; }
int PenaltyCard::getPenaltyPoints() { return penaltyPoints; }
void PenaltyCard::applyPenalty(Player& player) {
    player.setScore(player.getScore() - penaltyPoints);
}
void PenaltyCard::display() {
    if (getFaceUp()) {
        cout << getNumber() << " (Penalty: -" << penaltyPoints << ")";
    } else {
        cout << "*";
    }
}

// Player Implementation
Player::Player() : name("Player"), score(0) {}
Player::Player(string playerName) : name(playerName), score(0) {}
Player::~Player() {}
void Player::setName(string& playerName) { name = playerName; }
void Player::setScore(int playerScore) { score = playerScore; }
string Player::getName() { return name; }
int Player::getScore() { return score; }
void Player::displayScore() { cout << name << "'s Score: " << score << endl; }
void Player::addScore(int points) { score += points; }
void Player::deductScore(int points) { score -= points; }

// Deck Implementation
Deck::Deck() {
    grid = new Card**[4];
    for (int i = 0; i < 4; i++) {
        grid[i] = new Card*[4];
        for (int j = 0; j < 4; j++) {
            grid[i][j] = nullptr;
        }
    }

    deck = new Card*[16];
    for (int i = 0; i < 16; i++) {
        if (i < 12) deck[i] = new Card(i % 6 + 1);
        else if (i == 12 || i == 13) deck[i] = new BonusCard(i % 6 + 1, 2);
        else deck[i] = new PenaltyCard(i % 6 + 1, 1);
    }
}
Deck::~Deck() {
    for (int i = 0; i < 16; i++) delete deck[i];
    delete[] deck;
    for (int i = 0; i < 4; i++) delete[] grid[i];
    delete[] grid;
}
void Deck::shuffle() {
    srand(static_cast<unsigned>(time(0)));
    vector<int> indices(16);
    iota(indices.begin(), indices.end(), 0);
    random_shuffle(indices.begin(), indices.end());
    int index = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            grid[i][j] = deck[indices[index++]];
}
void Deck::displayGrid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j]->display();
            cout << " ";
        }
        cout << endl;
    }
}

void Deck::flipCard(int row, int col, bool faceUp) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4 && grid[row][col] != nullptr) {
        grid[row][col]->setFaceUp(faceUp);
    }
}

Card* Deck::getCard(int row, int col) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4) {
        return grid[row][col];
    }
    return nullptr;
}



// Main Function
int main() {
    Deck deck;
    deck.shuffle();

    cout << "Shuffled Grid:" << endl;
    deck.displayGrid();

    // Flip two cards in the grid
    deck.flipCard(0, 0, true);
    deck.flipCard(0, 1, true);

    cout << "\nUpdated Grid:" << endl;
    deck.displayGrid();

    return 0;
}

