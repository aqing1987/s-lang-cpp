// Referencing
// Demonstrates using references
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int myScore = 1000;
  int& mikesScore = myScore; // create a reference

  cout << "myScore is: " << myScore << endl;
  cout << "mikesScore is: " << mikesScore << endl;
  cout << "Adding 500 to myScore\n";
  myScore += 500;
  cout << "myScore is: " << myScore << endl;
  cout << "mikesScore is: " << mikesScore << endl;
  cout << "Adding 500 to mikesscore\n";
  mikesScore += 500;
  cout << "myScore is: " << myScore << endl;
  cout << "mikesScore is: " << mikesScore << endl;
  return 0;
}
