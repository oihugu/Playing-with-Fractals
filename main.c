
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <complex.h> 
#include <MLX42/MLX42.h>

#define WIDTH 1024
#define HEIGHT 1024
#define BPP sizeof(int32_t)
#define MAX_IT 100

static mlx_image_t* image;

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

double complex computeNext(double complex current, double complex constant) {
  double real_p =
      (creal(current) * creal(current)) - (cimag(current) * cimag(current));
  double complex_p = 2.0 * creal(current) * cimag(current);
  double complex complex_result = real_p + complex_p * I;
  return complex_result + constant;
}


double mod(double complex z) {
  return creal(z) * creal(z) + cimag(z) * cimag(z);
}


int computeIterations(double complex z, double complex constant,
                      int max_iterations) {
  double complex z_n = z;
  int iterations = 0;
  while (mod(z_n) < 4.0 && iterations < max_iterations){
      z_n = computeNext(z_n, constant);
      iterations++;
    }

  return iterations;
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


void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_mlx_data *data;
	data = param;

	
	if (ydelta > 0){
		data->scale += 0.3;
	}
	else if (ydelta < 0){
		data->scale -= 0.3;
	}
		

}

void init_data(t_mlx_data *data){
	data->mod_scale = 4.0;
}


typedef struct s_mlx_data
{
	mlx_t *mlx;
	float mod_scale;

}	t_mlx_data;



int32_t main(int32_t argc, const char* argv[])
{
	t_mlx_data data;
	unsigned char r, g, b, a;
	int iterations;
	float px, py;
	double complex constant = -0.8;

	float mod_scale = 4.0;


	mlx_set_setting(MLX_MAXIMIZED, true);
	data.mlx = mlx_init(WIDTH, HEIGHT, "FracTauz XDXDXDXDXDXD", true);

	init_data(&data);

	if (!data.mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	

	float scale = 1.0f / (HEIGHT / data->mod_scale);
	
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			px = ((x - WIDTH / 2.0) * scale) + 0;
			py = ((y - HEIGHT / 2.0) * scale) + 0;

			iterations = computeIterations(px + py * I, constant, MAX_IT);


			mapColorGradient(iterations, 1, MAX_IT, &r, &g, &b, &a);;
			mlx_put_pixel(img, x, y, get_rgba(r,g,b,a));

		}
	}

	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	mlx_scroll_hook(mlx, &my_scrollhook, &data);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}