/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:22:10 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/26 18:23:37 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tga_reader.h"

unsigned char	*runlengthcm(t_tga *tga, unsigned char *new)
{
	int		again;

	tga->new_i = 0;
	tga->data_i = 0;
	while (tga->new_i < ((tga->w * tga->h) * 4))
	{
		again = (tga->data[tga->data_i] & 0x7C) + 1;
		if (tga->data[tga->data_i] & 0x80)
		{
			while (again)
			{
				fill(tga, tga->cm, new, tga->cm_bpp);
				tga->new_i += 4;
				again--;
			}
			tga->data_i += (tga->data_bpp >> 3);
		}
		else
		{
			while (again)
			{
				fill(tga, tga->cm, new, tga->cm_bpp);
				tga->data_i += (tga->data_bpp >> 3);
				again--;
			}
		}
		tga->data_i += 1;
	}
	return (new);
}

unsigned char	*runlength(t_tga *tga, unsigned char *new)
{
	int		again;

	tga->new_i = 0;
	tga->data_i = 0;
	while (tga->new_i < (tga->w * tga->h * 4))
	{
		again = (tga->data[tga->data_i] & 0x7F) + 1;
		if ((tga->data[tga->data_i] & 0x80) == 0x80)
		{
			tga->data_i += 1;
			while (again)
			{
				fill(tga, tga->data, new, tga->data_bpp);
				tga->new_i += 4;
				again--;
			}
			tga->data_i += (tga->data_bpp >> 3);
		}
		else
		{
			tga->data_i += 1;
			while (again)
			{
				fill(tga, tga->data, new, tga->data_bpp);
//				printf("%d, %d, %d, %d\n", new[tga->new_i], new[tga->new_i + 1], new[tga->new_i + 2], new[tga->new_i + 3]);
				tga->new_i += 4;
				tga->data_i += (tga->data_bpp >> 3);
				again--;
			}
		}
	}
	printf("%d\t\t=>%d\n", tga->new_i, tga->w * tga->h * 4);
	return (new);
}

int				uncompress(t_tga *tga)
{
	unsigned char	*ret;

	printf("Compressed File\n");
	printf("Compressed value : %d\n", tga->compress);
	ret = NULL;
	if ((ret = (unsigned char *)malloc(sizeof(unsigned char) * tga->w * tga->h * 4)) == NULL)
		return (1);
	if (tga->compress > 9)
	{
		if ((ret = runlength(tga, ret)) == NULL)
			return (1);
	}
	else
	{
		if ((ret = runlengthcm(tga, ret)) == NULL)
			return (1);
	}
	free(tga->data);
	tga->data = ret;
	printf("Compressed Finished\n");
	return (0);
}
