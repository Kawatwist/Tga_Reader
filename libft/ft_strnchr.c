/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:56:09 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/13 19:10:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, size_t n)
{
	size_t		i;
	size_t		j;
	char		*ret;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	ret = (char *)s;
	while (ret[i] && j < n)
	{
		if (ret[i] == c)
		{
			j++;
		}
		i++;
	}
	if (j == n)
		return (&ret[i]);
	return (NULL);
}
