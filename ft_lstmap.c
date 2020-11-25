/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:04:36 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/25 18:36:52 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*cpy_list;

	if (!lst)
		return (NULL);
	if (!(list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	cpy_list = list;
	while (lst->next)
	{
		lst = lst->next;
		if (lst)
		{
			if (!(cpy_list->next = ft_lstnew((*f)(lst->content))))
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			cpy_list = cpy_list->next;
		}
	}
	return (list);
}
