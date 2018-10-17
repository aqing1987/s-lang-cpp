// Game Stats
// Demonstrates declaring and initializing variables
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int score;
  double distance;
  char playAgain;
  bool shieldsUp;
  short lives, aliensKilled;

  score = 0;
  distance = 1200.76;
  playAgain = 'y';
  shieldsUp = true;
  lives = 3;
  aliensKilled = 10;
  double engineTemp = 6572.89;

  cout << "\nscore: " << score << endl;
  cout << "distance: " << distance << endl;
  cout << "playagain: " << playAgain << endl;
  // skipping shieldsup since you don't generally print Boolean values
  cout << "lives: " << lives << endl;
  cout << "alienskilled: " << aliensKilled << endl;
  cout << "enginetemp: " << engineTemp << endl;

  int fuel;
  cout << "\nHow much fuel?";
  cin >> fuel;
  cout << "fuel: " << fuel << endl;

  typedef unsigned short int ushort;
  ushort bonus = 10;
  cout << "\nbonus: " << bonus << endl;
  return 0;
}
