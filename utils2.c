/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:56:34 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/11 23:57:35 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_fdf *mlx)
{
	mlx->param_x = mlx->param_x * mlx->zoom;
	mlx->param_y = mlx->param_y * mlx->zoom;
	mlx->param_x1 = mlx->param_x1 * mlx->zoom;
	mlx->param_y1 = mlx->param_y1 * mlx->zoom;
}

void	isometric(t_fdf *mlx, int z, int z1)
{
	mlx->param_x = (mlx->param_x - mlx->param_y) * cos(mlx->degree);
	mlx->param_y = (mlx->param_x + mlx->param_y) * sin(mlx->degree) - z;
	mlx->param_x1 = (mlx->param_x1 - mlx->param_y1) * cos(mlx->degree);
	mlx->param_y1 = (mlx->param_x1 + mlx->param_y1) * sin(mlx->degree) - z1;
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
	mlx->param_x += mlx->shift_x;
	mlx->param_y += mlx->shift_y;
	mlx->param_x1 += mlx->shift_x;
	mlx->param_y1 += mlx->shift_y;
}
