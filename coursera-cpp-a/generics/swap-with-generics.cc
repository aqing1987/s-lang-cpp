// Copyright 2018 Neil Chen, All rights reserved.

#include <iostream>
#include <complex>

using namespace std;

// "Generics" - programming using templates

template <class T>
inline void swap1(T& d, T& s) {
  T temp;
  temp = d;
  d = s;
  s = temp;
}

int main(int argc, char *argv[]) {
  int m = 5, n = 10;
  double x = 5.3, y = 10.6;
  complex<double> r(2.4, 3.5), s(3.4, 6.7);
  cout << "inputs: " << m << "," << n << endl;
  swap1(m, n);
  cout << "outputs: " << m << "," << n << endl;

  cout << "double inputs:" << x << "," << y << endl;
  swap1(x, y);
  cout << "double outputs:" << x << "," << y << endl;

  cout << "complex inputs:" << r << "," << s << endl;
  swap1(r, s);
  cout << "complex outputs:" << r << "," << s << endl;

  return 0;
}
