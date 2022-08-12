/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:52:19 by miskirik          #+#    #+#             */
/*   Updated: 2022/02/12 13:35:33 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	idx = 0;
	if (dst == src || !n)
		return (dst);
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (d);
}
