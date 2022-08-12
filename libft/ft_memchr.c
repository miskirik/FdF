/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:01:08 by miskirik          #+#    #+#             */
/*   Updated: 2022/01/29 07:40:08 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	a;
	size_t			counter;

	counter = 0;
	src = (unsigned char *)s;
	a = (unsigned char)c;
	while (n > counter)
	{
		if (*src == a)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}
