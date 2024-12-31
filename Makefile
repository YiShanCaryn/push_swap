# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yishan <yishan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 13:50:31 by yishan            #+#    #+#              #
#    Updated: 2024/12/30 11:46:45 by yishan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

LIB	=	-L./libft -lft

INCLUDE	=	-I.

SRCS =  push_swap.c\
		utils/utils.c\

OBJS = 	${SRCS:.c=.o}

LIBPATH	= 	libft/

${NAME}:	${OBJS}
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIB} -o $@

all : $(NAME)

clean :
		make clean -C ${LIBPATH}
		${RM} ${OBJS}

fclean : clean
		 make fclean -C ${LIBPATH}
		 ${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re