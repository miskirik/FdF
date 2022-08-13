/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:56:34 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/13 06:00:11 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_fdf *mlx)
{
	mlx->draw->param_x = mlx->draw->param_x * mlx->map->zoom;
	mlx->draw->param_y = mlx->draw->param_y * mlx->map->zoom;
	mlx->draw->param_x1 = mlx->draw->param_x1 * mlx->map->zoom;
	mlx->draw->param_y1 = mlx->draw->param_y1 * mlx->map->zoom;
}

void	isometric(t_fdf *mlx, int z, int z1)
{
	mlx->draw->param_x = (mlx->draw->param_x - mlx->draw->param_y) * cos(mlx->map->degree);
	mlx->draw->param_y = (mlx->draw->param_x + mlx->draw->param_y) * sin(mlx->map->degree) - z;
	mlx->draw->param_x1 = (mlx->draw->param_x1 - mlx->draw->param_y1) * cos(mlx->map->degree);
	mlx->draw->param_y1 = (mlx->draw->param_x1 + mlx->draw->param_y1) * sin(mlx->map->degree) - z1;
}

float	maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	shift(t_fdf *mlx)
{
	mlx->draw->param_x += mlx->map->shift_x;
	mlx->draw->param_y += mlx->map->shift_y;
	mlx->draw->param_x1 += mlx->map->shift_x;
	mlx->draw->param_y1 += mlx->map->shift_y;
}
