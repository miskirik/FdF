/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:58:24 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/13 05:46:08 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct s_draw
{
	float	param_x;
	float	param_y;
	float	param_x1;
	float	param_y1;
	int		color;
	int		color_flag;
	int		*cords_ptr;
}				t_draw;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		shift_x;
	int		shift_y;
	float	zoom;
	double	degree;
}				t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*data_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_draw	*draw;
	t_map	*map;
}				t_fdf;

void	fill_matrix(int *z, char *line);
void	read_map(char *file, t_fdf *mlx);
void	spec_data(t_fdf *mlx);
void	set_cord(t_fdf *mlx, int x, int y, int flag);
void	my_mlx_pixel_put(t_fdf *mlx, int x, int y, int color);
void	color(t_fdf *mlx, int z, int z1, int flag);
void	zoom(t_fdf *mlx);
void	isometric(t_fdf *mlx, int z, int z1);
void	bersenham(t_fdf *mlx);
void	shift(t_fdf *mlx);
void	draw(t_fdf *mlx);
void	file_error(void);
void	first_check(int argc, char **argv);
int		get_width(char *file);
int		get_height(char *file);
int		ft_count(const char *str, char c);
int		check_arg(char *str);
float	maxf(float a, float b);
float	mod(float num);
#endif
