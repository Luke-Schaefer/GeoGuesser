#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Player {
 protected:
  bool flag = false;
  string WordCategory;
  string Word;

 public:
  // pure virtual functions.. inheritance
  virtual string setWord() = 0;
  virtual void setDifficulty() = 0;
};

class Multiplayer : public Player {
 private:
  string Empty = "";

 public:
  string setWord();
  void setDifficulty();
};

class Singleplayer : public Player {
  string difficulty = "";
  int NumLives = 0;

  // populate map with difficulty levels
  unordered_map<int, vector<string>> cities = {
      {1, {"Oslo", "Munich", "Thessaloniki"}},
      {2, {"Cairo", "Havana", "Tallahassee"}},
      {3, {"Lima", "Durban", "Kalamazoo"}},
      {4, {"Bali", "Mumbai", "Yamoussoukro"}},
      {5, {"Perth", "Adelaide", "Chattanooga"}},
      {6, {"Milan", "Nagoya", "Liechtenstein"}},
      {7, {"Seoul", "Brussels", "Kongsvinger"}}};

  unordered_map<int, vector<string>> countries = {
      {1, {"Chad", "Greece", "Liechtenstein"}},
      {2, {"Peru", "Brazil", "Mozambique"}},
      {3, {"Cuba", "Canada", "Turkmenistan"}},
      {4, {"Fiji", "Russia", "Uzbekistan"}},
      {5, {"Togo", "France", "Kyrgyzstan"}},
      {6, {"Mali", "Sweden", "Afghanistan"}},
      {7, {"Laos", "Poland", "Bangladesh"}}};

  unordered_map<int, vector<string>> capitals = {
      {1, {"Bern", "Athens", "Antananarivo"}},
      {2, {"Oslo", "Beirut", "Ouagadougou"}},
      {3, {"Lima", "Manila", "AddisAbaba"}},
      {4, {"Cairo", "Berlin", "Thimphu"}},
      {5, {"Paris", "Jakarta", "PortoNovo"}},
      {6, {"Suva", "Havana", "Brazzaville"}},
      {7, {"Riga", "Seoul", "Ulaanbaatar"}}};

  unordered_map<int, vector<string>> regions = {
      {1, {"Lazio", "Bavaria", "Wolverhampton"}},
      {2, {"Texas", "Normandy", "Saskatchewan"}},
      {3, {"Punjab", "Tuscany", "Massachusetts"}},
      {4, {"Crete", "Quebec", "Transylvania"}},
      {5, {"Iowa", "Catalonia", "Newfoundland"}},
      {6, {"Ulster", "Andalusia", "Kalimantan"}},
      {7, {"Sicily", "Flanders", "Yunnan"}}};

 public:
  // setting values
  string setWord();
  void setDifficulty();
  // get remaining lives
  int getNumLives() const;
};

#endif /* PLAYER_H */
