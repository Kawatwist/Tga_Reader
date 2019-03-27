/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:10:47 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/09 23:19:39 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str;
	unsigned char *str2;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n)
	{
		if (*str != *str2)
			return (*str - *str2);
		str++;
		str2++;
		n--;
	}
	return (0);
}
