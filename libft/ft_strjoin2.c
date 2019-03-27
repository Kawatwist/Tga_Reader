/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:15:59 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/20 13:16:16 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		*ft_strjoin2(unsigned char *str, unsigned char *buff, int len_total, int len_buff)
{
	unsigned char	*new;
	int		i;

	i = -1;

	if (!str || !buff)
		return (NULL);
	if (!(new = (unsigned char *)malloc(sizeof(unsigned char) * len_total + len_buff + 1)))
		return (NULL);
	if (len_total != 0)
	{
			while (++i < len_total)
		new[i] = str[i];
	}
	int j = -1;
	while (++j < len_buff && (i++ < (len_total + len_buff)))
		new[i] = buff[j];
	new[len_total + len_buff] = '\0';
	free(str);
	return (new);
}
