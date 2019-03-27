/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:46:38 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/13 18:41:27 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countnumber(int *n, char *neg, int *min)
{
	int	i;
	int	nb;

	i = 1;
	if (*n < 0)
	{
		*neg = '-';
		if (*n == -2147483648)
		{
			*min = 1;
			*n = -2147483647;
		}
		*n *= -1;
		i++;
	}
	nb = *n;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		count;
	int		min;
	char	x;

	ret = NULL;
	x = '\0';
	min = 0;
	count = ft_countnumber(&n, &x, &min);
	if (!(ret = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	ret[count--] = '\0';
	while (count >= 0)
	{
		ret[count] = n % 10 + '0';
		n /= 10;
		count--;
	}
	if (x)
		ret[0] = '-';
	if (min == 1)
		ret[10] = '8';
	return (ret);
}
