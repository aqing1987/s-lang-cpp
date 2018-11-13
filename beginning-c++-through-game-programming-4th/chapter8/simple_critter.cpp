// Simple Critter
// Demonstrates creating a new type

#include <iostream>

using namespace std;

class Critter { // class definition -- defines a new type, Critter
 public:
  int m_Hunger; // data member
  void Greet(); // member function prototype
};

// member function definition
void Critter::Greet() {
  cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n";
}

int main(int argc, char *argv[]) {
  Critter crit1;
  Critter crit2;

  crit1.m_Hunger = 9;
  cout << "crit1's hunger level is " << crit1.m_Hunger << ".\n";
  crit2.m_Hunger = 3;
  cout << "crit2's hunger level is " << crit1.m_Hunger << ".\n";

  crit1.Greet();
  crit2.Greet();
  return 0;
}

