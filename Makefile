# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 18:08:22 by amaisonn          #+#    #+#              #
#    Updated: 2023/02/14 11:00:17 by amaisonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  lib/ft_putptr lib/ft_putchar_fd lib/ft_putstr_fd lib/ft_putnbr_fd lib/ft_putnbr_unsign_fd lib/ft_tolower lib/ft_toupper lib/ft_isalpha lib/ft_putnbr_base ft_printf

SRCS = 	$(addsuffix .c, ${SRC})

OBJS = ${SRCS:.c=.o}

FLAG = -Wall -Wextra -Werror

.c.o:
			gcc ${FLAG} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS} 

all: $(NAME)

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all
