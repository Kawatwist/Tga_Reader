/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:37:58 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/27 16:51:33 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tga_reader.h"

int		getheader(t_tga *tga)
{
	unsigned char		buff[18];

	if (read(tga->fd, &buff, 18) != 18)
		return (1);
	tga->id_len = buff[0];
	tga->datatype = buff[1];
	tga->compress = buff[2];
	tga->cm_start = buff[3] + (buff[4] * 0xFF);
	tga->cm_len = buff[5] + (buff[6] * 0xFF);
	tga->cm_bpp = buff[7];
	tga->xorigin = buff[8] + (buff[9] * 0xFF);
	tga->yorigin = buff[10] + (buff[11] * 0xFF);
	tga->w = buff[12] + (buff[13] * 0x100);
	tga->h = buff[14] + (buff[15] * 0x100);
	tga->data_bpp = buff[16];
	tga->descriptor = buff[17];
	return (0);
}

int		getcm(t_tga *tga)
{
	if (tga->cm_len != 0)
	{
		if ((tga->cm = (unsigned char *)malloc(sizeof(unsigned char)
						* (tga->cm_len * tga->cm_bpp >> 3))) == NULL)
			return (1);
		if (read(tga->fd, tga->cm, tga->cm_len * (tga->cm_bpp >> 3))
				!= tga->cm_len * (tga->cm_bpp >> 3))
			return (1);
	}
	return (0);
}

int		getinfo(t_tga *tga)
{
	if (tga->id_len != 0)
	{
		if ((tga->info = (unsigned char *)malloc(sizeof(unsigned char)
						* tga->id_len)) == NULL)
			return (1);
		if (read(tga->fd, tga->info, tga->id_len) != tga->id_len)
			return (1);
	}
	return (0);
}

int		getdata(t_tga *tga)
{
	if ((tga->data = (unsigned char *)malloc(sizeof(unsigned char)
					* tga->w * tga->h * ((tga->data_bpp >> 3)
						+ (tga->compress > 8 ? 1 : 0)))) == NULL)
		return (1);
	if (tga->compress < 8)
	{
		if (read(tga->fd, tga->data, tga->w * tga->h * (tga->data_bpp >> 3))
				!= (tga->w * tga->h * ((tga->data_bpp >> 3))))
			return (1);
	}
	else
		read(tga->fd, tga->data, tga->w * tga->h * ((tga->data_bpp >> 3) + 1));
	return (0);
}

int		getfile(t_tga *tga, const char *path)
{
	if (((tga->fd = open(path, O_RDONLY)) == -1))
		return (1);
	if (getheader(tga) || getinfo(tga) == 1
			|| getcm(tga) == 1 || getdata(tga) == 1)
	{
		ft_putstr("Parsing Header Failed\n");
		return (1);
	}
	return (0);
}
