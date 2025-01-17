#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Game {
 private:
  string UnknownWord;  // Stores the current state of the guessed word
  int CorrectGuess;    // Tracks the number of correct guesses for the current
                       // turn
  string Guess;        // Stores the current guessed letter
  int NumLives;
  int cummulative;
  string isPlayerReady;
  string NumPlayers;
  string UserPlayAgain;
  unordered_set<char> set;         // Tracks guessed characters
  unordered_map<char, int> count;  // Tracks character occurrences in the word
  unordered_map<string, string> wordHints;

 public:
  Game();
  void is_player_ready();
  string Number_of_Players();
  void defineUnknownWord(string Word);
  void PrintUnknownWord(string Word);
  int get_guess(string Word);
  int LoseLife();  // User loses life
  void GameWL(int NumLives, string Word);
  string PlayAgain();
  // reset + population functions
  void resetLives();
  void resetGuesses();
  void populateMap(string word);
  int getCummulative();
  bool hasWon(const string& Word) const;
};
