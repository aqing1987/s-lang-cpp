// planning the Pseudocode
// Create a critter
// While the player doesn't want to quit the game
//  present a menu of choices to the player
//  if the player wants to listen to the critter
//   make the critter talk
//  if the player wants to feed the critter
//   make the critter eat
//  if the player wants to play with the critter
//   make the critter play

// Critter Caretaker
// Simulates caring for a virtual pet

#include <iostream>

using namespace std;

class Critter {
 public:
  Critter(int hunger = 0, int boredom = 0);
  void Talk();
  void Eat(int food = 4);
  void Play(int fun = 4);

 private:
  int m_Hunger; // represent the critter's hunger level
  int m_Boredom; // represent its boredom level

  int GetMood() const;
  void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom):
    m_Hunger(hunger), m_Boredom(boredom) {
  
}

// As the sum of a critter's hunger and boredom levels, a critter's
// mood gets worse as the number increases.
inline int Critter::GetMood() const {
  return (m_Hunger + m_Boredom);
}

// invoked at the end of each member function where the critter does
// something (eats, plays, or talks) to simulate the passage of time.
void Critter::PassTime(int time) {
  m_Hunger += time;
  m_Boredom += time;
}

void Critter::Talk() {
  cout << "I'm a critter and I feel ";

  int mood = GetMood();
  if (mood > 15)
    cout << "mad.\n";
  else if (mood > 10)
    cout << "frustrated.\n";
  else if (mood > 5)
    cout << "okay.\n";
  else
    cout << "happy.\n";

  PassTime();
}

void Critter::Eat(int food) {
  cout << "Brruppp.\n";
  m_Hunger -= food;
  if (m_Hunger < 0)
    m_Hunger = 0;

  PassTime();
}

void Critter::Play(int fun) {
  cout << "Wheee!\n";

  m_Boredom -= fun;
  if (m_Boredom < 0)
    m_Boredom = 0;

  PassTime();
}

int main(int argc, char *argv[]) {
  Critter crit;

  crit.Talk();

  int choice;
  do {
    cout << "\nCritter Caretaker\n\n";
    cout << "0 - Quit\n";
    cout << "1 - Listen to your critter\n";
    cout << "2 - Feed your critter\n";
    cout << "3 - Play with your critter\n\n";

    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
      case 0:
        cout << "Good-bye.\n";
        break;

      case 1:
        crit.Talk();
        break;

      case 2:
        crit.Eat();
        break;

      case 3:
        crit.Play();
        break;

      default:
        cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
    }
  } while (choice != 0);

  return 0;
}
