# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 16:46:25 by mel-hiak          #+#    #+#              #
#    Updated: 2024/05/29 15:50:14 by mel-hiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunbr.c ft_lowerhexa.c \
		ft_upperhexa.c ft_printf.c

OBJECT = $(CFILES:.c=.o)

INCLUDE = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(NAME): $(OBJECT)
	@ar rc $(NAME) $?

all: $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
