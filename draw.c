/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:16:56 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/12 03:30:03 by miskirik         ###   ########.fr       */
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

	z = mlx->z_matrix[(int)mlx->param_y][(int)mlx->param_x];
	z1 = mlx->z_matrix[(int)mlx->param_y1][(int)mlx->param_x1];
	zoom(mlx);
	color(mlx, z, z1, mlx->color_flag);
	isometric(mlx, z, z1);
	shift(mlx);
	x_step = mlx->param_x1 - mlx->param_x;
	y_step = mlx->param_y1 - mlx->param_y;
	max = maxf(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(mlx->param_y - mlx->param_y1) ||
		(int)(mlx->param_x - mlx->param_x1))
	{
		my_mlx_pixel_put(mlx, mlx->param_x, mlx->param_y, mlx->color);
		mlx->param_x += x_step;
		mlx->param_y += y_step;
	}
}

void	draw(t_fdf *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			if (x < mlx->width - 1)
			{
				set_cord(mlx, x, y, 0);
				bersenham(mlx);
			}
			if (y < mlx->height - 1)
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
