/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:37:58 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/12 00:43:55 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(int *z, char *line)
{
	char	**data;
	int		c;

	c = 0;
	data = ft_split(line, ' ');
	while (data[c])
	{
		z[c] = ft_atoi(data[c]);
		free (data[c]);
		c++;
	}
	free (data);
}

int	get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		file_error();
	line = get_next_line(fd);
	if (line == NULL)
		file_error();
	width = ft_count(line, ' ');
	free (line);
	return (width);
}

int	get_height(char *file)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		file_error();
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (height);
}

void	read_map(char *file, t_fdf *mlx)
{
	int		c;
	int		fd;
	char	*line;

	c = 0;
	mlx->width = get_width(file);
	mlx->height = get_height(file);
	mlx->z_matrix = (int **)malloc(sizeof(int *) * (mlx->height + 1));
	while (c <= mlx->height)
	{
		mlx->z_matrix[c] = (int *)malloc(sizeof(int *) * (mlx->width + 1));
		c++;
	}
	fd = open(file, O_RDONLY);
	c = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(mlx->z_matrix[c], line);
		free (line);
		line = get_next_line(fd);
		c++;
	}
	close (fd);
}
