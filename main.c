/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:21:12 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/12 03:49:10 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*mlx;
	first_check(argc, argv);
	mlx = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "FdF");
	mlx->img = mlx_new_image(mlx->mlx_ptr, 1920, 1080);
	mlx->data_ptr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->size_line, &mlx->endian);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	spec_data(mlx);
	draw(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
