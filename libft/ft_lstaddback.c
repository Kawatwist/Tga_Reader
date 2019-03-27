/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:13:29 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/14 08:58:29 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddback(t_list **alst, t_list *elem)
{
	while ((*alst)->next != NULL)
		(*alst) = (*alst)->next;
	(*alst)->next = elem;
}
