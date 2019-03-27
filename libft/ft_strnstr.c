/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:00:51 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/13 09:41:29 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			lensrc;
	char			*dest;
	char			*src;

	dest = (char *)haystack;
	src = (char *)needle;
	lensrc = ft_strlen(src);
	while (*dest && len >= lensrc)
	{
		if (ft_memcmp(dest, src, lensrc) == 0)
			return (dest);
		dest++;
		len--;
	}
	return (NULL);
}
