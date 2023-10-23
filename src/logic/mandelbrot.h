#ifndef MANDELBROT_H
    #define MANDELBROT_H
    #include <stdlib.h>
    #include "complex.h" 
    #include "fractal.h"

    complex computeNext(complex current, complex constant);
    int computeIterations(complex z, complex constant, int max_iterations);
#endif