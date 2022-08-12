/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:36:51 by miskirik          #+#    #+#             */
/*   Updated: 2022/01/30 20:36:47 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s;

	s = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		p[s] = *(char *)s1;
		s1++;
		s++;
	}
	while (*s2 != '\0')
	{
		p[s] = *(char *)s2;
		s2++;
		s++;
	}
	p[s] = '\0';
	return (p);
}		
