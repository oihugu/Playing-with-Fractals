#include "fractal.h"
#include "complex.h"

complex computeNext(complex *current, complex *constant) {
  complex complex_result;
  complex_result.x =
      ((current->x * current->x) - (current->y * current->y)) + constant->x;
  complex_result.y = (2.0 * current->x * current->y) +  + constant->y;
  
  return complex_result;
}

int computeIterations(complex *z, complex *constant, int max_iterations) {
  complex z_n;

  z_n.x = z->x;
  z_n.y = z->y;

  int iterations = 0;
  while (mod(&z_n) < 4.0 && iterations < max_iterations){
      z_n = computeNext(&z_n, constant);
      iterations++;
    }

  return iterations;
}