# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomasse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:24:01 by lomasse           #+#    #+#              #
#    Updated: 2019/03/27 14:40:42 by lomasse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Tga

BASE_SRC		= main.c

TGA_SRC			= data.c										\
				  filldata.c									\
				  createpxl.c									\
				  uncompress.c									\
				  rot.c											\
				  tga_main.c

BASE_PATH		= ./

TGA_PATH		= ./src/

OBJ_PATH		= ./OBJ

SRCS			=	$(addprefix $(BASE_PATH), $(BASE_SRC))			\
					$(addprefix $(TGA_PATH), $(TGA_SRC))			\

INC				= -I ./includes

LIB				= -L ./libft/

GCC				= gcc

FLAGS			= -Wall -Wextra -Werror

OBJS			= $(addprefix $(OBJ), $(SRCS:.c=.o))

MAKELIB			= make re -C libft/

LIBFT			= -Llibft/ -lft

LIBMLX			= -L ./libui -lSDL2 -lSDL2_mixer

FRAME			= -framework OpenGL -framework AppKit


%.o: %.c ./includes/doom.h ./includes/tga_reader.h
	@$(GCC) $(INC) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJS)
	@$(GCC) -o $@ `sdl2-config --cflags --libs` $(OBJS) $(LIB) $(LIBFT) $(LIBMLX) $(FRAME) $(FLAGS) -g -fsanitize=address

all : $(NAME)

cake : $(NAME)
	@clear ; cat texture/portal.txt ; echo "\n\n" ; cat texture/cake.txt ;

clean :
	@rm -rf $(OBJS) ; echo "Obj Cleaned"

fclean : clean
	@rm -rf $(NAME) ; echo "Exec Cleaned"

re : fclean all

relibft : 
	$(MAKELIB)

.PHONY : all clean fclean re
