#ifndef COLORS_H
    #define COLORS_H
    #include <stdlib.h>    
    #include "../logic/fractal.h"

    int get_rgba(int r, int g, int b, int a);
    void mapColorGradient(double value, double min, double max, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a);
#endif