/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:13:44 by miskirik          #+#    #+#             */
/*   Updated: 2022/02/15 16:57:39 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*void ft_del(void *lst)
{
	free(lst);
}
void *ft_f(void *lst)
{
	*((int *)lst)=*((int *)lst)+1;
	return(lst);

}*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*cnt;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		cnt = f(lst->content);
		tmp = ft_lstnew(cnt);
		if (tmp == NULL)
		{
			del(cnt);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
