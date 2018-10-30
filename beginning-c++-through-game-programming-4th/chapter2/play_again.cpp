// Play Again
// Demonstrates while loop
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  char again = 'y';

  while (again == 'y') {
    cout << "\n**Played an exciting game**";
    cout << "\nDo you want to play again? (y/n): ";
    cin >> again;
  }
  cout << "\nOkay, bye." << endl;
  
  return 0;
}
