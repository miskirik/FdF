#include "fdf.h"

void handler_ok(t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr,mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr,mlx->img);
	mlx->img=mlx_new_image(mlx->mlx_ptr,1920,1080);
	mlx->data_ptr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->size_line, &mlx->endian);
	draw(mlx);
}
void	handler_m(t_fdf *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 1L << 17, mouse_c, mlx);
	mlx_hook(mlx->win_ptr, 4, 1L << 11, mouse_r, mlx);
	mlx_hook(mlx->win_ptr, 5, 1L << 12, mouse_r, mlx);
}
int handler_k(int key, t_fdf *mlx)
{
	int i;

	i=0;

	if(key==KEY_W||key==KEY_A||key==KEY_S||key==KEY_D)
		shift_k(key,mlx);
	else if(key==KEY_UP||key==KEY_DOWN)
		degree_k(key,mlx);
	else if(key==KEY_Z||key==KEY_X)
		color_k(key,mlx);
	else if(key==KEY_BACKSPACE)
		spec_data(mlx);
	else if (key==KEY_ESCAPE)
		free_data(mlx);
	handler_ok(mlx);
	return(0);
}
