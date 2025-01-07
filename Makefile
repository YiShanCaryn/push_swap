# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yisho <yisho@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 13:50:31 by yishan            #+#    #+#              #
#    Updated: 2025/01/07 10:21:50 by yisho            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS =  push_swap.c\
		utils/add_index.c\
		utils/algorithm_s.c\
		utils/algorithm_rr.c\
		utils/algorithm_r.c\
		utils/check_sort.c\
		utils/utils_sort.c\
		libft/libft.a\

$(NAME) :
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

.PHONY: all clean fclean re