/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:08:25 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/10 01:59:46 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	*str2;
	unsigned char		c2;

	str = (unsigned char *)dst;
	str2 = (const unsigned char *)src;
	c2 = (unsigned char)c;
	while (n)
	{
		*str = *str2;
		if (*str++ == c2)
			return (str);
		str2++;
		n--;
	}
	return (NULL);
}
