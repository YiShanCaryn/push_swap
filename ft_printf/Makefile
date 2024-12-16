# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yisho <yisho@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 11:27:44 by yisho             #+#    #+#              #
#    Updated: 2024/11/07 11:07:23 by yisho            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRC
NAME = libftprintf.a
SRC_FILES = $(SRC_PATH)ft_print_ptr.c 		\
			$(SRC_PATH)ft_print_unsigned.c 	\
			$(SRC_PATH)ft_printf_hex.c 		\
			$(SRC_PATH)ft_printf_utils.c	\
			$(SRC_PATH)ft_printf_itoa.c		\
			$(SRC_PATH)ft_printf.c

#HEADER
HDR_PATH = ./

#OBJS
OBJS = $(SRC_FILES:.c=.o)

#FLAGS
CC = gcc
F_GCC = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(F_GCC) -I$(HDR_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re