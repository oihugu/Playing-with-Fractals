#include "fractal.h"
#include <string.h>

int	init_data(t_mlx_data *mlx_data)
{
	memset(mlx_data, 0, sizeof(*mlx_data));
    mlx_data->mod_scale = 4.0;
	
    return (0);
}
