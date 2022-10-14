# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 18:35:58 by jebouche          #+#    #+#              #
#    Updated: 2022/07/20 18:47:58 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = empty_map_maker.c get_map_info.c map_from_si.c find_square_in_map.c \
	   manage_structs_and_memory.c print_solved_grid.c ft_atoi.c map_fill.c \
	   read_input.c ft_bsq.c map_from_file.c

OBJS = empty_map_maker.o get_map_info.o map_from_si.o find_square_in_map.o \
	   manage_structs_and_memory.o print_solved_grid.o ft_atoi.o map_fill.o \
	   read_input.o ft_bsq.o map_from_file.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
