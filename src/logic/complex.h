#ifndef COMPLEX_H
    #define COMPLEX_H
    #include <stdlib.h> 
    #include "fractal.h"

    typedef struct custom_complex
    {
        double          x;
        double          y;
    }	complex;

    double mod(complex *z);
#endif