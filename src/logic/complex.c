#include "fractal.h"
#include "complex.h"

double mod(complex *z){
  return z->x * z->x + z->y * z->y;
}

