/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 06:40:03 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/15 13:33:26 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s2[j] || s1[i])
	{
		if (s1[i])
			str[k++] = s1[i++];
		else
			str[k++] = s2[j++];
	}
	str[k] = '\0';
	return (str);
}
