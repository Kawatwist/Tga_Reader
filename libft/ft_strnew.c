/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 07:37:25 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/09 07:18:54 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	size++;
	if (!(str = (char *)malloc(sizeof(char) * (int)size)))
		return (NULL);
	while (size != 0)
	{
		str[size] = '\0';
		size--;
	}
	str[0] = '\0';
	return (str);
}
