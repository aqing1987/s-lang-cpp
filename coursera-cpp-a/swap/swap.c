#include <stdio.h>

// typical C idiom for passing parameters that need modification.
// In C each function in a given scope must have a unique name (no
// function overloading)
// in C within scope, all funciton names have to be unique, otherwise
// it would be ambiguous in the C.
void swap(int* i, int* j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void swap_double(double* i, double* j) {
  double temp = *i;
  *i = *j;
  *j = temp;
}

int main(int argc, char *argv[]) {
  int m = 5, n = 10;
  double x = 5.3, y = 10.6;

  printf("inputs: %d, %d\n", m, n);
  swap(&m, &n);
  printf("outputs: %d, %d\n", m, n);

  printf("double inputs: %lf, %lf\n", x, y);
  swap_double(&x, &y);
  printf("double outputs: %lf, %lf\n", x, y);

  return 0;
}
