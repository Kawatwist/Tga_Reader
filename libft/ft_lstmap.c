/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 03:19:47 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/13 09:39:54 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*next;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(next = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	new = next;
	while (lst)
	{
		tmp = f(lst);
		if (!(next->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		next = next->next;
	}
	return (new);
}
