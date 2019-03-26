/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filldata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:51:45 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/25 14:57:07 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tga_reader.h"

static void	bpp32(unsigned char *base, unsigned char *tofill, int index, int index2)
{
	tofill[index2] = base[index + 3];
	tofill[index2 + 1] = base[index + 2];
	tofill[index2 + 2] = base[index + 1];
	tofill[index2 + 3] = base[index];
}

static void	bpp24(unsigned char *base, unsigned char *tofill, int index, int index2)
{
	tofill[index2] = 255;
	tofill[index2 + 1] = base[index + 2];
	tofill[index2 + 2] = base[index + 1];
	tofill[index2 + 3] = base[index];
}

static void	bpp16(unsigned char *base, unsigned char *tofill, int index, int index2)
{
	tofill[index2] = (base[index] & 0x80) != 0 ? 255 : 255;
	tofill[index2 + 1] = ((((base[index + 1] & 0x7C) >> 2) * 255) / 31);
	tofill[index2 + 2] = ((base[index + 1] & 0x03) << 3);
	tofill[index2 + 2] += ((base[index] & 0xE0) >> 5);
	tofill[index2 + 3] = (((base[index] & 0x1F) * 255) / 31);
	tofill[index2 + 2] *= 255 / 31;
}

static void	bpp8(unsigned char *base, unsigned char *tofill, int index, int index2)
{
	tofill[index2] = ((base[index] & 0x80) != 0 ? 255 : 0);
	tofill[index2 + 1] = base[index] & 0x7F;
	tofill[index2 + 2] = base[index] & 0x7F;
	tofill[index2 + 3] = base[index] & 0x7F;
}

void		fill(t_tga *tga, unsigned char *base, unsigned char *tofill, int bpp)
{
	if (bpp == 32)
		bpp32(base, tofill, tga->data_i, tga->new_i);
	else if (bpp == 24)
		bpp24(base, tofill, tga->data_i, tga->new_i);
	else if (bpp == 16)
		bpp16(base, tofill, tga->data_i, tga->new_i);
	else
		bpp8(base, tofill, tga->data_i, tga->new_i);
}
