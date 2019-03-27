/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:08:40 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/13 14:44:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenwithoutspace(char const *s)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = ft_strlen(s);
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ' || s[i] == '\0')
		i++;
	while ((s[k] == '\t' || s[k] == '\n' || s[k] == ' ' || s[k] == 0) && k)
		k--;
	if (k == 0)
		return (0);
	return ((k + 1) - i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	if (s == NULL)
		return (NULL);
	size = ft_lenwithoutspace(s);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (j < size)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
