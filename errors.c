/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:20:00 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/12 03:27:35 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_error(void)
{
	ft_printf("File read problem. Please check file permission and name.");
	exit(1);
}

void	first_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Invalid Arguman input\n");
		exit(1);
	}
	if (!(ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".fdf", 4)))
	{
		ft_printf("Error. Invalid Map extension use .fdf");
		exit(1);
	}
}
