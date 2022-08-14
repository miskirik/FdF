#include "fdf.h"

int mouse_c(t_fdf *mlx)
{
	free_data(mlx);
	return(0);
}
int mouse_r(int key,int x,int y,t_fdf *mlx)
{
	(void)x;
	(void)y;
	if (key == 4)
		mlx->map->zoom += 1;
	if (key == 5)
		mlx->map->zoom -=1;
	handler_ok(mlx);
	draw(mlx);
	return (0);
}
void shift_k(int key,t_fdf *mlx)
{
	if(key==KEY_W)
		mlx->map->shift_y +=10;
	else if (key==KEY_A)
		mlx->map->shift_x +=10;
	else if(key==KEY_S)
		mlx->map->shift_y -=10;
	else if(key==KEY_D)
		mlx->map->shift_x -=10;
}
void	degree_k(int key, t_fdf *mlx)
{
	if(key==KEY_UP)
		mlx->map->degree +=0.1;

	else if(key==KEY_DOWN)
		mlx->map->degree -=0.1;
}
void	color_k(int key,t_fdf *mlx)
{
	if(key==KEY_C)
		mlx->draw->color_flag =1;
	if(key==KEY_V)
		mlx->draw->color_flag =0;
	if(key==KEY_T)
		mlx->draw->color_flag =2;
}

