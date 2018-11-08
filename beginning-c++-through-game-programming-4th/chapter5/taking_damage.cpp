// Taking Damage
// Demonstrates function inlining
#include <iostream>

using namespace std;

inline int radiation(int health) {
  return (health / 2);
}

int main(int argc, char *argv[]) {
  int health = 80;

  cout << "Your health is " << health << endl;
  health = radiation(health);
  cout << "After radiation exposure your health is " << health << endl;
  health = radiation(health);
  cout << "After radiation exposure your health is " << health << endl;
  health = radiation(health);
  cout << "After radiation exposure your health is " << health << endl;
  return 0;
}
