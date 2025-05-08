# 🃏 Memory Match Card Game

## 📋 General Description
The **Memory Match Card Game** is a turn-based game where two players take turns revealing cards from a shuffled grid. The game ends when all pairs of cards are matched, and the player with the highest score is declared the winner.

## 🎯 Functional Requirements
- **Player Turns**: Players take alternating turns to reveal cards.
- **Scoring Rules**:
    - Match standard cards to gain points.
    - Special cards (Bonus and Penalty) have unique effects.
- **Game End**: The game ends when all cards are matched, and the winner is announced.

## 🛠️ Class Structure
- **Card Class**: Includes `StandardCard`, `BonusCard`, and `PenaltyCard` with methods for revealing, hiding, and displaying cards.
- **Player Class**: Manages player information such as name and score.
- **Deck Class**: Handles the grid of cards and their functionalities.
- **Game Class**: Implements the main game logic, including player turns, scoring, and determining the winner.

## 🔄 Game Flow
1. 🟦 Display the initial grid with all cards hidden.
2. 👥 Show player information and scores.
3. 🎴 Allow the current player to select two cards to reveal.
4. 🔢 Update the grid and scores based on the revealed cards.
5. 🔄 Switch turns and repeat until all cards are matched.
6. 🏆 Announce the winner or declare a tie.


## 🏫 Faculty Information
- **University**: German International University
- **Course**: Programming III, Winter Semester 2024/2025
- **Instructor**: Dr. Nada Sharaf