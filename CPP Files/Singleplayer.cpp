#include <stdlib.h>

#include <ctime>
#include <iostream>
#include <string>
#include <thread>

#include "../Header Files/Player.h"

using namespace std;

// Function to get difficulty level from user
void Singleplayer::setDifficulty() {
  while (difficulty != "E" && difficulty != "M" && difficulty != "H") {
    cout << "Easy (E) | Medium (M) | Hard (H): ";
    cin >> difficulty;
  }
  if (difficulty == "E") NumLives = 8;
  if (difficulty == "M") NumLives = 6;
  if (difficulty == "H") NumLives = 4;
  system("clear");
}

// Function to set the word based on the selected category and difficulty
string Singleplayer::setWord() {
  unordered_map<string, unordered_map<int, vector<string>>*> categoryMap = {
      {"1", &cities}, {"2", &countries}, {"3", &capitals}, {"4", &regions}};

  // Continue to select input while not valid
  while (!flag) {
    cout << "Cities (1) | Countries (2) | Capital Cities (3) | Regions (4): ";
    cin >> WordCategory;

    if (categoryMap.find(WordCategory) == categoryMap.end()) continue;

    flag = true;

    // Generate random index for a word of the specified difficulty
    srand(static_cast<unsigned int>(time(0)));

    auto& selectedCategory = *categoryMap[WordCategory];
    int randomIndex = rand() % selectedCategory.size();

    // Select word based on difficulty
    const vector<string>& words = selectedCategory[randomIndex + 1];
    if (difficulty == "E") {
      Word = words.front();
    } else if (difficulty == "M") {
      Word = words[1];
    } else {
      Word = words.back();
    }

    system("clear");
  }

  return Word;
}

// Override getNumLives() to return the number of lives for the singleplayer
// game
int Singleplayer::getNumLives() const { return NumLives; }
