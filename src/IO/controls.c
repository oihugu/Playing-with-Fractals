#include "../logic/fractal.h"

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_mlx_data *data;
	data = param;

	
	if (ydelta > 0){
		data->mod_scale += 0.3;
	}
	else if (ydelta < 0){
		data->mod_scale -= 0.3;
	}
		

}