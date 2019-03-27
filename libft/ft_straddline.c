/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:32:53 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/06 10:14:37 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddline(char *str, char c)
{
	int		len;
	char	*pos;
	char	*tmp;
	char	*newhead;

	if (!(pos = ft_strchr(str, c)))
		return (NULL);
	len = pos - str;
	if (len < 1 || !(tmp = ft_strndup(str, len + 1))
			|| !(newhead = ft_strndup(pos + 1, ft_strlen(pos))))
		return (NULL);
	free(str);
	str = ft_strjoinfree(newhead, tmp, 3);
	return (str);
}
