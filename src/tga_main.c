/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:26:36 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/27 16:47:22 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tga_reader.h"

void		*free_tga(t_tga *tga)
{
	if (tga != NULL)
	{
		tga->data != NULL ? free(tga->data) : 0;
		tga->cm != NULL ? free(tga->cm) : 0;
		tga->info != NULL ? free(tga->info) : 0;
		tga->done != NULL ? free(tga->done) : 0;
	}
	return (NULL);
}

int			inittga(t_tga *tga)
{
	tga->data = NULL;
	tga->cm = NULL;
	tga->info = NULL;
	tga->done = NULL;
	tga->fd = 0;
	tga->data_i = 0;
	tga->new_i = 0;
	return (0);
}

t_tga		*load_tga(const char *path)
{
	t_tga	*tga;

	tga = NULL;
	if ((tga = (t_tga*)malloc(sizeof(t_tga))) == NULL)
		return (NULL);
	if (inittga(tga) == 1)
		return (free_tga(tga));
	if (getfile(tga, path) == 1)
	{
		ft_putstr("Invalid file or path\n");
		return (free_tga(tga));
	}
	if (tga->compress > 8)
	{
		if (uncompress(tga) == 1)
			return (free_tga(tga));
	}
	else if (createpxl(tga) == 1)
		return (free_tga(tga));
	if (tga->xorigin == 0)
		rotatepxl(tga);
	if (tga->yorigin == 0)
		sym_vert(tga);
	return (tga);
}
