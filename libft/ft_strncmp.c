/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:23:59 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/13 09:41:07 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*w;
	unsigned char	*w2;
	int				i;

	if (n == 0)
		return (0);
	w = (unsigned char *)s1;
	w2 = (unsigned char *)s2;
	i = 0;
	while (w[i] == w2[i] && w[i] != '\0' && w2[i] != '\0' && --n > 0)
		i++;
	return (w[i] - w2[i]);
}
