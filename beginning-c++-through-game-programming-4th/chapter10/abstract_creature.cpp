// abstract creature
// demonstrates abstract classes

#include <iostream>
using namespace std;

// abstract class
class Creature {
 public:
  Creature(int health = 100);
  virtual void Greet() const = 0; // pure virtual member function
  virtual void DisplayHealth() const;

 protected:
  int m_Health;
};

Creature::Creature(int health): m_Health(health) {}

void Creature::DisplayHealth() const {
  cout << "health: " << m_Health << endl;
}

class Orc: public Creature {
 public:
  Orc(int health = 120);
  virtual void Greet() const;
};

Orc::Orc(int health): Creature(health) {}

void Orc::Greet() const {
  cout << "The orc grunts hello.\n";
}

int main(int argc, char *argv[]) {
  Creature* pCreature = new Orc();
  pCreature->Greet();
  pCreature->DisplayHealth();
  return 0;
}


