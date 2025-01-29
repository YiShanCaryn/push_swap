# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yishan <yishan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 13:50:31 by yishan            #+#    #+#              #
#    Updated: 2025/01/09 15:36:30 by yishan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

LIBFT = libft/libft.a

SRCS =  push_swap.c\
		utils/add_index.c\
		utils/algorithm_s.c\
		utils/algorithm_rr.c\
		utils/algorithm_r.c\
		utils/algorithm_push.c\
		utils/check_sort.c\
		utils/utils_sort.c\
		utils/quick_sort.c

OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all : $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft/libft.a:
	make bonus -C libft


fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(OBJS);
	make clean -C libft

re : fclean all

.PHONY: all clean fclean re