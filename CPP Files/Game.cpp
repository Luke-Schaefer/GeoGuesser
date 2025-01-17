#include "../Header Files/Game.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Game::Game() {
  cummulative = 0;
  isPlayerReady = "";
  NumPlayers = "";
  UnknownWord = "";
  UserPlayAgain = "Y";
}

// Determines whether the player is ready to commence the game.
void Game::is_player_ready() {
  while (isPlayerReady != "Y" && isPlayerReady != "N") {
    cout << "Instructions (Y/N): ";
    cin >> isPlayerReady;
  }
  if (isPlayerReady == "Y") {
    cout << "Welcome to GeoGuesser, a text-based adventure game! Here are the "
            "rules:"
         << endl;
    cout << "\t1. The goal is to correctly guess the hidden word before "
            "running out of lives."
         << endl;
    cout << "\t2. The number of lives depends on the chosen difficulty level:"
         << endl;
    cout << "\t   - Easy: 8 lives" << endl;
    cout << "\t   - Medium: 6 lives" << endl;
    cout << "\t   - Hard: 4 lives" << endl;
    cout << "\t3. If you run out of lives before guessing the word, you lose."
         << endl;
    cout << "\t4. Successfully guessing the word with lives remaining means "
            "you win!"
         << endl;
    cout << endl;
  }

  while (isPlayerReady != "S") {
    cout << "Start (S): ";
    cin >> isPlayerReady;
  }
  system("clear");
}

// Asks user for number of Players
string Game::Number_of_Players() {
  while ((NumPlayers != "S") && (NumPlayers != "M")) {
    cout << "SinglePlayer (S) | Multiplayer (M): ";
    cin >> NumPlayers;
  }
  return NumPlayers;
}

void Game::defineUnknownWord(string Word) {
  UnknownWord = string(Word.length(),
                       '_');  // Ensure UnknownWord is properly initialized.
}

void Game::PrintUnknownWord(string Word) {
  for (char c : UnknownWord) {
    cout << c;
  }
  cout << endl;
}

int Game::get_guess(string Word) {
  cout << "Guess: ";
  cin >> Guess;

  // Validate the guess
  while (Guess.length() != 1 || !isalpha(Guess[0]) ||
         set.find(Guess[0]) != set.end()) {
    cout << "Invalid input. Please enter a single unused letter." << endl;
    cout << "Guess: ";
    cin >> Guess;
  }

  char letter = tolower(Guess[0]);
  set.insert(letter);

  CorrectGuess = 0;
  for (int i = 0; i < Word.length(); ++i) {
    if (tolower(Word[i]) == letter && UnknownWord[i] == '_') {
      UnknownWord[i] = Word[i];  // Update UnknownWord with the correct guess
      CorrectGuess++;
      cummulative++;
    }
  }

  return CorrectGuess;
}

int Game::LoseLife() {
  NumLives--;
  return NumLives;
}

void Game::GameWL(int NumLives, string Word) {
  cout << endl;
  if (cummulative == Word.length()) {
    cout << "Congratulations! You won the game!" << endl;
  } else {
    cout << "Game Over! You lost." << endl;
  }
  cout << "The word was: " << Word << endl << endl;
}

// asks user if they wish to play again
string Game::PlayAgain() {
  UserPlayAgain = "";
  while (UserPlayAgain != "Y" && UserPlayAgain != "N") {
    cout << "Play again(Y/N)? ";
    cin >> UserPlayAgain;
  }
  cummulative = 0;
  system("clear");
  return UserPlayAgain;
}

// resets lives
void Game::resetLives() { NumLives = 10; }
void Game::resetGuesses() { set.clear(); }

void Game::populateMap(string word) {
  for (char c : word) {
    count[c]++;
  }
}

int Game::getCummulative() { return cummulative; }

bool Game::hasWon(const string& Word) const {
  return cummulative == Word.size();
}
