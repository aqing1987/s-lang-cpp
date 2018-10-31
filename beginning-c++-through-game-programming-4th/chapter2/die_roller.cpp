// Die Roller
// Demonstrates generating random numbers
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
  // seed random number generator
  srand(static_cast<unsigned int>(time(0)));
  int randomNumber = rand(); // generate random number

  cout << "max random num: " << RAND_MAX << endl;

  // get a number between 1 and 6
  int die = (randomNumber % 6) + 1;
  cout << "You rolled a " << die << endl;
  return 0;
}
