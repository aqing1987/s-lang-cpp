// Copyright 2018 Neil Chen, All rights reserved.

#include <iostream>

using namespace std;

#ifdef C_TEST
double sum(double data[], int size) {
  double s = 0.0;
  int i;

  for (i = 0; i < size; ++i)
    s += data[i];

  return s;
}
#endif

// Generic SUM an array
// ideas: data is not mutable use a const
// s will default to 0
//
// sum(scores, 92);
// sum(scores, 92, 58);
// same function two different signatures
template <class T> // T is generic type
T sum(const T data[], int size, T s = 0) {
  for (int i = 0; i < size; ++i) {
    s += data[i]; // += must work for T
  }
  return s;
}

int main(int argc, char *argv[]) {
  cout << "template for sum() " << endl;

  int a[] = {1, 2, 3};
  double b[] = {2.1, 2.2, 2.3};

  cout << sum(a, 3) << endl;
  cout << sum(a, 3, 10) << endl;
  cout << sum(b, 3) << endl;
  return 0;
}
