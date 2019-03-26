/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:54:50 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/25 15:32:19 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_READER_H
# define TGA_READER_H

# include "../libft/libft.h"
# include "../libui/SDL2/SDL.h"
# include <fcntl.h>
# include <sys/stat.h>

typedef struct		s_tga
{
	unsigned char	*cm;			// DONE
	unsigned char	*data;			// DONE
	unsigned char	*done;			// DONE
	unsigned char	*info;
	int				id_len;			// =>
	int				datatype;
	int				compress;
	int				cm_start;
	int				cm_len;
	int				cm_bpp;
	int				xorigin;
	int				yorigin;
	int				w;
	int				h;
	int				data_bpp;
	int				descriptor;		// <=
	int				data_len;
	int				fd;
	int				data_i;
	int				new_i;
	int				truevision;
}					t_tga;

void			sym_vert(t_tga *tga);
void			rotatepxl(t_tga *tga);
void			fill(t_tga *tga, unsigned char *base, unsigned char *tofill, int bpp);
unsigned char 	*pxlbasecm(t_tga *tga, unsigned char *newstr);
unsigned char	*pxlbase(t_tga *tga, unsigned char *newstr);
int				createpxl(t_tga *tga);
int				uncompress(t_tga *tga);
int				getheader(t_tga *tga);
int				getcm(t_tga *tga);
int				getdata(t_tga *tga);
int				getfile(t_tga *tga, const char *path);
void			*cleartga(t_tga *tga);
int				inittga(t_tga *tga);
t_tga			*load_tga(const char *path);

#endif
