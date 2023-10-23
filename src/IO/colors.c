#include "../logic/fractal.h"


int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}


void mapColorGradient(double value, double min, double max, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a) {
    // Define the color gradient values
    unsigned char colors[][4] = {
        {0x73, 0x03, 0xc0, 0xff},
        {0xec, 0x38, 0xbc, 0xff},
        {0xfd, 0xef, 0xf9, 0xff}
    };
    int numColors = sizeof(colors) / sizeof(colors[0]);

    // Calculate the index in the new range
    int index = (int)((value - min) / (max - min) * (numColors - 1));

    // Ensure the index is within bounds
    if (index < 0) {
        index = 0;
    } else if (index >= numColors - 1) {
        index = numColors - 2;
    }

    // Get the two nearest colors
    unsigned char *color1 = colors[index];
    unsigned char *color2 = colors[index + 1];

    // Calculate the interpolation factor
    double factor = (value - min) / (max - min) * (numColors - 1) - index;

    // Interpolate between the two colors
    for (int i = 0; i < 3; i++) {
        unsigned char c1 = color1[i];
        unsigned char c2 = color2[i];
        // Calculate the interpolated color component
        unsigned char interpolatedComponent = (unsigned char)((1.0 - factor) * c1 + factor * c2);
        // Store the interpolated component in the output RGB
        switch (i) {
            case 0:
                *r = interpolatedComponent;
                break;
            case 1:
                *g = interpolatedComponent;
                break;
            case 2:
                *b = interpolatedComponent;
                break;
        }
    }

    // Set the alpha value
    *a = 0xff; // Fully opaque alpha value
}