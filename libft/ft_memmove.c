/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:09:48 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/09 23:15:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	str = (char *)dst;
	str2 = (char *)src;
	if (str > str2 && (str2 + len) > str)
		while (len-- > 0)
			str[len] = str2[len];
	else
		while (len-- != 0)
		{
			*str = *str2;
			str++;
			str2++;
		}
	return (dst);
}
