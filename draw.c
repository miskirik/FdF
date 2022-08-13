/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:16:56 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/13 05:52:44 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bersenham(t_fdf *mlx)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = mlx->map->z_matrix[(int)mlx->draw->param_y][(int)mlx->draw->param_x];
	z1 = mlx->map->z_matrix[(int)mlx->draw->param_y1][(int)mlx->draw->param_x1];
	zoom(mlx);
	color(mlx, z, z1, mlx->draw->color_flag);
	isometric(mlx, z, z1);
	shift(mlx);
	x_step = mlx->draw->param_x1 - mlx->draw->param_x;
	y_step = mlx->draw->param_y1 - mlx->draw->param_y;
	max = maxf(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(mlx->draw->param_y - mlx->draw->param_y1) ||
		(int)(mlx->draw->param_x - mlx->draw->param_x1))
	{
		my_mlx_pixel_put(mlx, mlx->draw->param_x, mlx->draw->param_y, mlx->draw->color);
		mlx->draw->param_x += x_step;
		mlx->draw->param_y += y_step;
	}
}

void	draw(t_fdf *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x < mlx->map->width - 1)
			{
				set_cord(mlx, x, y, 0);
				bersenham(mlx);
			}
			if (y < mlx->map->height - 1)
			{
				set_cord(mlx, x, y, 1);
				bersenham(mlx);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}
