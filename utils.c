/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:06:21 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/12 05:39:41 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count(const char *str, char c)
{
	int	i;
	int	cc;

	i = 0;
	cc = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		cc++;
		while (str[i] != '\0' && str[i] == c)
			i++;
	}
	return (cc);
}

void	spec_data(t_fdf *mlx)
{
	mlx->color = 0xff0000;
	mlx->color_flag = 0;
	mlx->degree = 0.8;
	mlx->shift_x = 760;
	mlx->param_x = 0;
	mlx->param_x1 = 0;
	mlx->param_y = 0;
	mlx->shift_y = 340;
	mlx->param_y1 = 0;
	mlx->zoom = 30;
}

void	set_cord(t_fdf *mlx, int x, int y, int flag)
{
	mlx->param_x = x;
	mlx->param_y = y;
	if (flag == 0)
	{
		mlx->param_y1 = y;
		mlx->param_x1 = x + 1;
	}
	else
	{
		mlx->param_y1 = y + 1;
		mlx->param_x1 = x;
	}
}

void	my_mlx_pixel_put(t_fdf *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = mlx->data_ptr + (y * mlx->size_line + \
				x * (mlx->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	color(t_fdf *mlx, int z, int z1, int flag)
{
	if ((z1 || z) && flag == 1)
		mlx->color = 0x4E4AD5;
	else if ((z1 || z) && !flag)
		mlx->color = 0xDEC039;
	else if ((z1 || z) && flag == 2)
		mlx->color = 0xFFFFFF;
	else if (!(z || z1) && flag == 2)
		mlx->color = 0xE30A17;
	else if (flag != 2)
		mlx->color = 0xFFFFFF;
}
