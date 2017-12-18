# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpajot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:37:12 by bpajot            #+#    #+#              #
#    Updated: 2017/12/18 14:44:40 by bpajot      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LMLX_FLAGS = -L ../minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LFT_FLAGS = -L libft/ -lft
PATH_SRCS = ./
PATH_OBJS = ./
PATH_INCS = ./
FILES = main.c read.c display.c line.c print.c proj.c legend.c image.c
SRCS = $(addprefix $(PATH_SRCS), $(FILES))
OBJS = $(addprefix $(PATH_OBJS), $(FILES:.c=.o))
INCS = fdf.h libft/libft.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo "CREATION DE L'EXECUTABLE\n"
	@$(CC) $(CC_FLAGS) -o $@ $^ $(LMLX_FLAGS) $(LFT_FLAGS)
	@echo "👍  COMPILATION REUSSIE 👍\\n"

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c
	@echo "CREATION $@\n"
	@$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "👍  COMPILATION REUSSIE 👍\\n"

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJS)
	@/bin/rm -f display.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
