// Copyright (C) 2018 Neil Chen. All rights reserved.
//
// The following program computes the probability for
// dice possibilities.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int kSides = 6; // replaces many sharp defines

inline int r_sides() {
  return (rand() % kSides + 1);
}

int main() {
  const int n_dice = 2;
  int d1, d2;

  srand(clock()); // initialize seed
  cout << "\nEnter number of trials:";
  int trials;
  cin >> trials; // compare to scanf
  int* outcomes = new int[n_dice*kSides + 1];
  memset(outcomes, 0, n_dice*kSides + 1);

  for (int j = 0; j < trials; ++j) {
    outcomes[(d1 = r_sides()) + (d2 = r_sides())]++;
  }
  cout << "probability\n";

  for (int j = 0; j < n_dice * kSides; ++j) {
    cout << "j = " << j << " p = "
         << static_cast<double>(outcomes[j])/trials
         << endl;
  }

  delete [] outcomes;

  return 0;
}
