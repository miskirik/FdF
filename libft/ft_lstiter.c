/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:15:18 by miskirik          #+#    #+#             */
/*   Updated: 2022/02/13 20:43:25 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*void ft_f(void *lst)
{
	printf("%d",*(int*)lst);
}*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst && f)
	{
		while (lst != NULL)
		{
			tmp = lst->next;
			f(lst->content);
			lst = tmp;
		}
	}
}
