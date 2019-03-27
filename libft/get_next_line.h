/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:56:50 by lomasse           #+#    #+#             */
/*   Updated: 2018/11/23 17:10:06 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 500

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <stdio.h>
# include "libft.h"

typedef struct		s_gnl
{
	size_t			fd;
	size_t			find;
	char			tmp[BUFF_SIZE];
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
