/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:23:36 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/10 01:59:19 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str;
	unsigned char	*str2;
	int				i;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0')
		i++;
	return (str[i] - str2[i]);
}
