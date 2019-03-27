/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:38:12 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/15 13:35:31 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countchar(char const *s, char c, int *i)
{
	int	nb;

	nb = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		nb++;
		*i += 1;
	}
	return (nb);
}

static int		ft_countword(char const *s, char c)
{
	int	i;
	int	word;
	int	check;

	i = 0;
	word = 0;
	check = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			check = 1;
		}
		else if (check == 1 && s[i] != c)
		{
			check = 0;
			word++;
		}
		i++;
	}
	return (word);
}

static char		*ft_makestr(char const *s, char c, int *i)
{
	char	*str;
	int		chara;
	int		i2;
	int		j;

	str = NULL;
	i2 = *i;
	j = 0;
	chara = ft_countchar(s, c, i);
	if (!(str = (char *)malloc(sizeof(char) * chara + 1)))
		return (NULL);
	while (j < chara)
		str[j++] = s[i2++];
	str[j] = '\0';
	*i = i2;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	word = ft_countword(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * word + 1)))
		return (NULL);
	while (word--)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		tab[j] = ft_makestr(s, c, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
