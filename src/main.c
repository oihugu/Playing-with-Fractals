#include "logic/fractal.h"
#include "logic/init_data.h"
#include "logic/mandelbrot.h"
#include "logic/complex.h"
#include "IO/colors.h"
#include "IO/controls.h"
#include "IO/error.h"



int32_t main(int32_t argc, const char* argv[])
{
	t_mlx_data data;
	unsigned char r, g, b, a;
	int iterations;
	float px, py;
	complex p;
	complex constant;
	constant.x = -0.8;
	constant.y = 0;


	mlx_set_setting(MLX_MAXIMIZED, true);
	data.mlx_ptr = mlx_init(WIDTH, HEIGHT, "FracTauz XDXDXDXDXDXD", true);

	init_data(&data);

	if (!data.mlx_ptr)
		ft_error();


	mlx_image_t* img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	

	float scale = 1.0f / (HEIGHT / data.mod_scale);
	
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			p.x = ((x - WIDTH / 2.0) * scale) + 0;
			p.y = ((y - HEIGHT / 2.0) * scale) + 0;
			
			iterations = computeIterations(p, constant, MAX_IT);


			mapColorGradient(iterations, 1, MAX_IT, &r, &g, &b, &a);;
			mlx_put_pixel(img, x, y, get_rgba(r,g,b,a));

		}
	}

	if (!img || (mlx_image_to_window(data.mlx_ptr, img, 0, 0) < 0))
		ft_error();

	/* mlx_scroll_hook(data.mlx_ptr, &my_scrollhook, &data); */
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);

	return (EXIT_SUCCESS);
}