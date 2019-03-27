/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpxl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:18:07 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/27 16:46:44 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tga_reader.h"

unsigned char	*pxlbasecm(t_tga *tga, unsigned char *new)
{
	int	index;

	index = 0;
	tga->new_i = 0;
	tga->data_i = 0;
	while (tga->new_i <= ((tga->w * tga->h * 4)))
	{
		fill(tga, tga->cm, new, tga->cm_bpp);
		index++;
		tga->new_i += 4;
		tga->data_i = tga->data[index] * (tga->cm_bpp >> 3);
	}
	return (new);
}

unsigned char	*pxlbase(t_tga *tga, unsigned char *new)
{
	tga->new_i = 0;
	tga->data_i = 0;
	while (tga->new_i < (tga->w * tga->h * 4))
	{
		fill(tga, tga->data, new, tga->data_bpp);
		tga->new_i += 4;
		tga->data_i += (tga->data_bpp >> 3);
	}
	return (new);
}

int				createpxl(t_tga *tga)
{
	unsigned char *ret;

	if ((ret = (unsigned char *)malloc(sizeof(unsigned char) * tga->w
					* tga->h * 4)) == NULL)
		return (1);
	if (tga->compress == 2 || tga->compress == 3)
		ret = pxlbase(tga, ret);
	else
		ret = pxlbasecm(tga, ret);
	free(tga->data);
	tga->data = &(ret[0]);
	return (0);
}
