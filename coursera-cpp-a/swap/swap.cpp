#include <iostream>

using namespace std;

// c++ has overloading and call by reference
// overloading:
// "signature maching algorithm"
// The two routines need different types or numbers of parameters.
// call by reference:
// automatically choose to use the variable locally, without copy.
inline void swap(int& i, int& j) {
  int temp = i;
  i = j;
  j = temp;
}

inline void swap(double& i, double& j) {
  double temp = i;
  i = j;
  j = temp;
}

int main(int argc, char *argv[]) {

  int m = 5, n = 10;
  double x = 5.3, y = 10.6;
  cout << "inputs: " << m << "," << n << endl;
  swap(m, n);
  cout << "outputs: " << m << "," << n << endl;

  cout << "double inputs:" << x << "," << y << endl;
  swap(x, y);
  cout << "double outputs:" << x << "," << y << endl;
  
  return 0;
}

