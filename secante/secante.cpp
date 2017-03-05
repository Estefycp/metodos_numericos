#include <cstdio>
#include <cmath>

#ifndef MINERR
#define MINERR 1E-15
#endif

typedef double (* vFunctionCall)(double x);

double secante(vFunctionCall fun, double x1, double x2) {
  double x0;
  int i = 0;
  do {
    x0=x1;
    x1=x2;
    x2 = x1 - (x1-x0) * fun(x1) / (fun(x1) - fun(x0));
    i++;
  } while ( fabs (x1-x2) > MINERR );

  fprintf(stderr, "Iteraciones: %d\n", i);
  fprintf(stderr, "Error: %f\n", fabs(x1 - x2));
  return x2;
}

double f1(double x) {
  return pow(x, 2) - 4;
}

double f2(double x) {
  return pow(x, 3) - x - 11;
}

double f3(double x) {
  return atan(x);
}

double f4(double x) {
  return cos(3 * x) - x;
}

double f5(double x) {
  return pow(x, 1 / 3.0);
}

int main(int argc, char const *argv[]) {
  // fprintf(stderr, "%f\n", secante(f1, 1, 5));
  // fprintf(stderr, "%f\n", secante(f1, -100, -101));
  //
  fprintf(stderr, "%f\n", secante(f2, -100, 100));
  // fprintf(stderr, "%f\n", secante(f2, -10, 5));

  // fprintf(stderr, "%f\n", secante(f3, 1, 8));
  // fprintf(stderr, "%f\n", secante(f4, -1.39174, 1.39174));
  // fprintf(stderr, "%f\n", secante(f5, 1, 0));
  // fprintf(stderr, "%f\n", secante(f5, -20, 20));
  return 0;
}
