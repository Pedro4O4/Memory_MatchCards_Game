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
///////////////////////////////////////////////////

// Default Constructor
Game::Game() : player1("Player 1"), player2("Player 2"), currentPlayer(1) {}

// Destructor
Game::~Game() {}

// Initialize the game
void Game::initializeGame() {
    std::cout << "Welcome to the 2D Card Matching Game!" << std::endl;

    // Shuffle the deck
    std::cout << "Shuffling cards..." << std::endl;
    deck.shuffle();

    // Display initial grid
    std::cout << "\nInitial Card Grid:" << std::endl;
    deck.displayGrid();
}

// Handle a single player's turn
void Game::playTurn() {
    Player& current = (currentPlayer == 1) ? player1 : player2;

    std::cout << "\n" << current.getName() << "'s turn!" << std::endl;

    // Input for first card
    int row1, col1;
    std::cout << "Enter row and column for the first card (e.g., 0 1): ";
    std::cin >> row1 >> col1;

    // Flip the first card
    deck.flipCard(row1, col1, true);
    deck.displayGrid();

    // Input for second card
    int row2, col2;
    std::cout << "Enter row and column for the second card (e.g., 1 2): ";
    std::cin >> row2 >> col2;

    // Flip the second card
    deck.flipCard(row2, col2, true);
    deck.displayGrid();

    // Check if the two cards match
    Card* card1 = deck.getCard(row1, col1);
    Card* card2 = deck.getCard(row2, col2);

    if (card1 && card2 && card1->getNumber() == card2->getNumber()) {
        std::cout << "It's a match!" << std::endl;

        // Handle special cards
        if (auto* bonusCard = dynamic_cast<BonusCard*>(card1)) {
            current.addScore(bonusCard->getBonusPoints());
            std::cout << "Bonus! +" << bonusCard->getBonusPoints() << " points." << std::endl;
        } else if (auto* penaltyCard = dynamic_cast<PenaltyCard*>(card1)) {
            current.deductScore(penaltyCard->getPenaltyPoints());
            std::cout << "Penalty! -" << penaltyCard->getPenaltyPoints() << " points." << std::endl;
        }

        current.addScore(10); // Add points for a successful match
    } else {
        std::cout << "Not a match!" << std::endl;

        // Flip cards back face-down
        deck.flipCard(row1, col1, false);
        deck.flipCard(row2, col2, false);
    }

    // Switch to the other player
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Display the current scores
void Game::displayScores() {
    player1.displayScore();
    player2.displayScore();
}

// Start the game loop
void Game::start() {
    initializeGame();

    // Game loop
    int turns = 0;
    while (turns < 8) { // Max 8 turns since there are 16 cards
        playTurn();
        displayScores();
        turns++;
    }

    // Determine the winner
    std::cout << "\nGame Over!" << std::endl;
    if (player1.getScore() > player2.getScore()) {
        std::cout << player1.getName() << " wins!" << std::endl;
    } else if (player1.getScore() < player2.getScore()) {
        std::cout << player2.getName() << " wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}



int main() {

    Game game;
    game.start();

    return 0;
}

