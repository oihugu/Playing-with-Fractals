#ifndef FRACTAL
    #define FRACTAL
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <MLX42/MLX42.h>

    #define WIDTH 1024
    #define HEIGHT 1024
    #define BPP sizeof(int32_t)
    #define MAX_IT 100


    typedef struct s_mlx_data
    {
        mlx_t			*mlx_ptr;
        mlx_image_t		*image;
        double          mod_scale;
    }	t_mlx_data;


#endif