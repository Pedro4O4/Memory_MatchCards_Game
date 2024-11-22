#include <bits/stdc++.h>
using namespace std;
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
#include "Card.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "Player.h"
#include "Deck.h"
Card::Card() : number(0), isFaceUp(false) {}

Card::Card(int num) : number(num), isFaceUp(false) {}

Card::~Card() {}

void Card::setNumber(int num) {
    number = num;
}

void Card::setFaceUp(bool faceUp) {
    isFaceUp = faceUp;
}

int Card::getNumber(){
    return number;
}

bool Card::getFaceUp(){
    return isFaceUp;
}

void Card::display(){
    if (isFaceUp) {
        cout << number;
    } else {
        cout << "*";
    }
}
////////////////////////////////////////////////////////////
BonusCard::BonusCard() : Card(), bonusPoints(0) {}

// Parameterized Constructor
BonusCard::BonusCard(int num, int points) : Card(num), bonusPoints(points) {}

// Destructor
BonusCard::~BonusCard() {}

void BonusCard::setBonusPoints(int points) {
    bonusPoints = points;
}

int BonusCard::getBonusPoints() {
    return bonusPoints;
}

// Overridden display method
void BonusCard::display(){
    if (getFaceUp()) {
        cout << getNumber() << " (Bonus: +" << bonusPoints << ")";
    } else {
        cout << "*";
    }
}
/////////////////////////////////////////////////

PenaltyCard::PenaltyCard() : Card(), penaltyPoints(0) {}

PenaltyCard::PenaltyCard(int num, int points) : Card(num), penaltyPoints(points) {}

PenaltyCard::~PenaltyCard() {}

void PenaltyCard::setPenaltyPoints(int points) {
    penaltyPoints = points;
}

int PenaltyCard::getPenaltyPoints(){
    return penaltyPoints;
}
void PenaltyCard::applyPenalty(Player& player) {
    player.setScore(player.getScore() - penaltyPoints); // Deduct penalty points from the player's score
}

// Overridden display method
void PenaltyCard::display(){
    if (getFaceUp()) {
        cout << getNumber() << " (Penalty: -" << penaltyPoints << ")"; // Show number and penalty points if face-up
    } else {
        cout << "*"; // Show placeholder (*) if face-down
    }
}
//////////////////////////////////////////////
// Default Constructor
Player::Player() : name("Player"), score(0) {}

Player::Player(string playerName) : name(playerName), score(0) {}


Player::~Player() {}


void Player::setName(string& playerName) {
    name = playerName;
}

void Player::setScore(int playerScore) {
    score = playerScore;
}

string Player::getName(){
    return name;
}

int Player::getScore(){
    return score;
}

void Player::displayScore(){
    std::cout << name << "'s Score: " << score << std::endl;
}

void Player::addScore(int points) {
    score += points;
}

void Player::deductScore(int points) {
    score -= points;
}
////////////////////////////////////////////////
// Constructor
Deck::Deck() {
    // Allocate memory for the deck (16 cards)
    deck = new Card[16];

    // Initialize grid pointers to nullptr
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = nullptr;
        }
    }

    // Populate the deck with cards
    for (int i = 0; i < 16; i++) {
        deck[i] = Card(i % 8 + 1); // Cards 1-8 appear twice
    }
}

// Destructor
Deck::~Deck() {
    delete[] deck;

    // Clean up the grid
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j] = nullptr; // Grid only points to existing cards
            }
        }
    }
}

// Add a card to the grid
void Deck::addCard(Card* card) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == nullptr) {
                grid[i][j] = card;
                return;
            }
        }
    }
}

// Shuffle the deck and assign cards to the grid
void Deck::shuffle() {
    srand(static_cast<unsigned>(time(0)));

    // Generate shuffled indices for the deck
    vector<int> indices(16);
    for (int i = 0; i < 16; i++) {
        indices[i] = i;
    }
    random_shuffle(indices.begin(), indices.end());

    // Assign shuffled cards to the grid
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = &deck[indices[index++]];
        }
    }
}

// Display the current layout of the grid
void Deck::displayGrid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j]->display(); // Display card details
            cout << " ";
        }
        cout << endl;
    }
}





int main() {
    Card c1(5);       // Create a card with number 5
    c1.display();     // Output: * (since it is face-down)
    cout << endl;
    c1.setFaceUp(true); // Flip the card face-up
    c1.display();       // Output: 5
    cout<<endl;
/////////////////////////////////
    // Create a BonusCard with number 7 and bonus points of 2
    BonusCard bCard(7, 2);

    // Display the card (initially face-down)
    bCard.display(); // Output: *
    cout << endl;

    // Flip the card face-up
    bCard.setFaceUp(true);

    // Display the card again
    bCard.display(); // Output: 7 (Bonus: +2)
    cout<<endl;
//////////////////////////////////
    PenaltyCard pCard(9, 3);

    // Display the card (initially face-down)
    pCard.display(); // Output: *
    cout << endl;

    // Flip the card face-up
    pCard.setFaceUp(true);

    // Display the card again
    pCard.display(); // Output: 9 (Penalty: -3)
    cout<<endl;
//////////////////////////////////////
// Create a player
    Player player1("Ahmed");

    // Display initial score
    player1.displayScore(); // Output: Ahmed's Score: 0

    // Add points to the player's score
    player1.addScore(10);
    player1.displayScore(); // Output: Ahmed's Score: 10

    // Deduct points from the player's score
    player1.deductScore(3);
    player1.displayScore(); // Output: Ahmed's Score: 7
    cout<<endl;
    //////////////////////////////
    Deck deck;

    // Shuffle the deck
    deck.shuffle();

    // Display the grid
    cout << "Shuffled Grid:" << endl;
    deck.displayGrid();


    return 0;
}
