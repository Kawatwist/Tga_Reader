/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:07:11 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/10 01:59:59 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str;
	const char	*str2;

	str = dst;
	str2 = src;
	while (n > 0)
	{
		*str++ = *str2++;
		n--;
	}
	return (dst);
}
