// Give me a number
// Demonstrates default function arguments
#include <iostream>
#include <string>
using namespace std;

int askNumber(int high, int low = 1) {
  int num;
  do {
    cout << "enter a number" << " (" << low << " - " << high << "): ";
    cin >> num;
  } while (num > high || num < low);

  return num;
}

int main(int argc, char *argv[]) {
  int number = askNumber(5);
  cout << "Thanks for entering: " << number << "\n\n";
  number = askNumber(10, 5);
  cout << "Thanks for entering: " << number << "\n\n";
  return 0;
}


