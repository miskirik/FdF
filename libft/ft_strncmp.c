/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:16:26 by miskirik          #+#    #+#             */
/*   Updated: 2022/02/03 00:24:05 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (s1[a] && s2[a] && s1[a] == s2[a] && a < n)
		a++;
	if (a == n)
		return (0);
	return (((unsigned char)s1[a]) - ((unsigned char)s2[a]));
}	
