# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 19:53:33 by mgadzhim          #+#    #+#              #
#    Updated: 2025/12/24 11:12:40 by mgadzhim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC			= $(wildcard *.c)

OBJ			= $(SRC:.c=.o)

HEADER		= libft.h

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@ -fPIE

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ}

all	: $(NAME)
	
clean	:
	rm -f ${OBJ}
	
fclean	: clean
	rm -f $(NAME)

re	: fclean all

bonus: ${OBJ}
	ar rcs ${NAME} ${OBJ}

.PHONY: all clean fclean re bonus