/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:08:00 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/27 17:02:27 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tga_reader.h"

static void		swap_bytes(t_tga *tga, unsigned char *new, int i, int j)
{
	new[j + (i * tga->w * 4)] = tga->data[(i * tga->w * 4)
		+ ((tga->w * 4) - j)];
	new[j + (i * tga->w * 4) + 1] = tga->data[(i * tga->w * 4)
		+ ((tga->w * 4) - j) - 3];
	new[j + (i * tga->w * 4) + 2] = tga->data[(i * tga->w * 4)
		+ ((tga->w * 4) - j) - 2];
	new[j + (i * tga->w * 4) + 3] = tga->data[(i * tga->w * 4)
		+ ((tga->w * 4) - j) - 1];
}

void			sym_vert(t_tga *tga)
{
	int				j;
	int				i;
	unsigned char	*done;

	j = 0;
	i = 0;
	if ((done = (unsigned char *)malloc(sizeof(unsigned char)
					* tga->w * tga->h * 4)) == NULL)
		return ;
	while (i < tga->h)
	{
		j = 0;
		while (j < tga->w * 4)
		{
			swap_bytes(tga, done, i, j);
			j += 4;
		}
		i += 1;
	}
	free(tga->data);
	tga->data = done;
}

void			rotatepxl(t_tga *tga)
{
	int				i;
	int				nb;
	unsigned char	*done;

	nb = 0;
	i = 0;
	if ((done = (unsigned char *)malloc(sizeof(unsigned char)
					* tga->w * tga->h * 4)) == NULL)
		return ;
	while (i <= (tga->w * tga->h * 4))
	{
		done[((tga->w * tga->h * 4) - (i + 0))] = tga->data[i];
		done[((tga->w * tga->h * 4) - (i + 3))] = tga->data[i + 1];
		done[((tga->w * tga->h * 4) - (i + 2))] = tga->data[i + 2];
		done[((tga->w * tga->h * 4) - (i + 1))] = tga->data[i + 3];
		i += 4;
	}
	free(tga->data);
	tga->data = done;
}
