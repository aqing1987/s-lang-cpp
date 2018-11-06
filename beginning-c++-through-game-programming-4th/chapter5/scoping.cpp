// Scoping
// Demonstrates scopes
#include <iostream>

using namespace std;

void func() {
  int var = -5; // local variable in func()
  cout << "In func() var is: " << var << "\n\n";
}

int main(int argc, char *argv[]) {
  int var = 5; // local variable in main()
  cout << "In main() var is: " << var << endl;

  func();

  cout << "Back in main() var is: " << var << endl;

  {
    cout << "In main() in a new scope var is: " << var << endl;
    cout << "Creating new var in new scope.\n";
    int var = 10; // variable in new scope, hides other variable named var
    cout << "In main() in a new scope var is: " << var << endl;
  }

  cout << "At end of main() var created in new scope no longer exists.\n";
  cout << "At end of main() var is: " << var << endl;
  return 0;
}
