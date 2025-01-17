#include <memory>

#include "../Header Files/Game.h"
#include "../Header Files/Player.h"
#include "Multiplayer.cpp"
#include "Singleplayer.cpp"

using namespace std;
#include <iostream>
#include <string>

int main() {
  system("clear");
  Game game;
  game.is_player_ready();

  string UserPlayAgain = "Y";
  while (UserPlayAgain == "Y") {
    game.resetLives();
    game.resetGuesses();

    string numplayer = game.Number_of_Players();
    string Word;
    int NumLives;

    // Player setup
    if (numplayer == "M") {
      unique_ptr<Player> player(new Multiplayer());
      Word = player->setWord();
      NumLives = 10;
    } else {
      unique_ptr<Singleplayer> player(new Singleplayer());
      player->setDifficulty();
      Word = player->setWord();
      NumLives = player->getNumLives();
    }

    game.defineUnknownWord(Word);  // Define the initial unknown word
    game.populateMap(Word);        // Populate the map for letter counting

    cout << "The word is " << Word.length() << " characters long." << endl;

    // Game loop for guessing
    while (NumLives > 0) {
      game.PrintUnknownWord(Word);

      int NumCorrect = game.get_guess(Word);  // Get the player's guess

      if (game.hasWon(Word)) {        // Check if the player has won
        game.GameWL(NumLives, Word);  // Player wins the game
        break;
      }

      if (NumCorrect == 0) {  // Incorrect guess, lose a life
        NumLives--;
        cout << NumLives << " remaining lives." << endl;
      }
    }

    if (NumLives == 0) {  // If the player runs out of lives
      game.GameWL(NumLives, Word);
    }

    // Ask if the player wants to play again
    UserPlayAgain = game.PlayAgain();
  }

  cout << "Thanks for playing!" << endl;
  return 0;
}
