// Array Passer
// Demonstrates relationship between pointers and arrays
#include <iostream>

using namespace std;

void increase(int* const array, const int NUM_ELEMENTS) {
  for (int i = 0; i < NUM_ELEMENTS; ++i)
    array[i] += 500;
}

void display(const int* const array, const int NUM_ELEMENTS) {
  for (int i = 0; i < NUM_ELEMENTS; ++i)
    cout << array[i] << endl;
}

int main(int argc, char *argv[]) {
  cout << "Creating an array of high score.\n\n";
  const int NUM_SCORES = 3;
  int highScores[NUM_SCORES] = {5000, 3500, 2700};
  cout << "Displaying scores using array name as a constant pointer.\n";
  cout << *highScores << endl;
  cout << *(highScores + 1) << endl;
  cout << *(highScores + 2) << "\n\n";

  cout << "Increasing scores by pasing array as a constant pointer.\n\n";
  increase(highScores, NUM_SCORES);
  cout << "Displaying scores by passing array as a constant pointer to a constant\n";
  display(highScores, NUM_SCORES);
  return 0;
}
