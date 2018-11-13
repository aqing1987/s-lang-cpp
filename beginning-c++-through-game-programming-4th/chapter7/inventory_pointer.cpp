// Inventory Pointer
// Demonstrates returning a pointer
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string* ptrToElement(vector<string>* const pVec, int i) {
  return &((*pVec)[i]);
}

int main(int argc, char *argv[]) {
  vector<string> inventory;

  inventory.push_back("sword");
  inventory.push_back("armor");
  inventory.push_back("shield");

  // displays string object pointed to by returned pointer points to
  cout << "Sending the object pointed to by returned pointer to cout:\n";
  cout << *(ptrToElement(&inventory, 0)) << "\n\n";

  // assigns one pointer to another -- inexpensive assignment
  cout << "Assigning the returned pointer to another pointer.\n";
  string* pStr = ptrToElement(&inventory, 1);
  cout << "Sending the object pointed to by new pointer to cout:\n";
  cout << *pStr << "\n\n";

  // copies a string object -- expensive assignment
  cout << "Assigning object pointed to by pointer to a string object.\n";
  string str = *(ptrToElement(&inventory, 2));
  cout << "Sending the new string object to cout:\n";
  cout << str << "\n\n";

  // altering the string object through a returned pointer
  cout << "Altering an object through a returned pointer.\n";
  *pStr = "Healing Potion";
  cout << "Sending the altered object to cout:\n";
  cout << inventory[1] << endl;
  return 0;
}
