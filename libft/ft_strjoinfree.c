/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:15:59 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/20 18:31:43 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char const *dst, char const *src, size_t n)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!dst || !src)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	if (!(new = (char *)malloc(sizeof(char) *
					(ft_strlen(src) + ft_strlen(dst) + 1))))
		return (NULL);
	while (dst[i] || src[j])
	{
		if (dst[i])
			new[k++] = dst[i++];
		else
			new[k++] = src[j++];
	}
	new[k] = '\0';
	n == 1 ? free((void *)dst) : free((void *)src);
	if (n == 3)
		free((void *)dst);
	return (new);
}
