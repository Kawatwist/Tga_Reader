/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:12:44 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/23 22:35:56 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((unsigned int)str[i + 1] == 0x00)
			return (i + 1);
		if ((unsigned int)str[i + 2] == 0x00)
			return (i + 2);
		if ((unsigned int)str[i + 3] == 0x00)
			return (i + 3);
		i += 4;
	}
	return (i);
}
