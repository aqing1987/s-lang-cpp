// triple
// Demonstrates function overloading
#include <iostream>
#include <string>

using namespace std;

int triple(int num) {
  return (num * 3);
}

string triple(string text) {
  return (text + text + text);
}

int main(int argc, char *argv[]) {
  cout << "Tripling 5: " << triple(3) << endl;
  cout << "Tripling 'gamer': " << triple("gamer") << endl;
  return 0;
}
