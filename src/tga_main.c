/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:26:36 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/26 18:13:37 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tga_reader.h"
#include "../../includes/doom.h"

void		*cleartga(t_tga *tga)
{
	if (tga != NULL)
	{
		printf("FREE HERE\n");
	}
	return (NULL);
}

int			inittga(t_tga *tga)
{
	(void)tga;
	return (0);
}

t_tga		*load_tga(const char *path)
{
	t_tga	*tga;

	tga = NULL;
	printf("%s\n", path);
	if ((tga = (t_tga*)malloc(sizeof(t_tga))) == NULL)
		return (NULL);
	if (inittga(tga) == 1)
		return (cleartga(tga));
	if (getfile(tga, path) == 1)
	{
		ft_putstr("Invalid file or path\n");
		return (cleartga(tga));
	}
	printf("Data get\n");
	if (tga->compress > 8)
	{
		if (uncompress(tga) == 1)
			return (cleartga(tga));
	}
	else if (createpxl(tga) == 1)
		return (cleartga(tga));
	if (tga->xorigin == 0)
		rotatepxl(tga);
	if (tga->yorigin == 0)
		sym_vert(tga);
	printf("Load_tga end\n");
	return (tga);
}
