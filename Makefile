# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 13:27:51 by mel-hiak          #+#    #+#              #
#    Updated: 2024/05/31 18:48:07 by mel-hiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BNAME = so_long_bonus

CFILES = ./src/so_long.c \
			./src/about_map.c \
			./src/ft_check_error.c \
			./src/util_map.c \
			./ft_printf/ft_lowerhexa.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_putchar.c \
			./ft_printf/ft_putnbr.c \
			./ft_printf/ft_putstr.c \
			./ft_printf/ft_putunbr.c \
			./ft_printf/ft_upperhexa.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./src/handle_moves.c \
			./src/handle2_moves.c \
			./src/put_to_window.c \
			./src/xpm_to_image.c \
			./src/flood_fill.c \


CBONUS = ./bonus/so_long_bonus.c \
			./bonus/about_map.c \
			./bonus/ft_check_error.c \
			./bonus/util_map.c \
			./ft_printf/ft_lowerhexa.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_putchar.c \
			./ft_printf/ft_putnbr.c \
			./ft_printf/ft_putstr.c \
			./ft_printf/ft_putunbr.c \
			./ft_printf/ft_upperhexa.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./bonus/flood_fill_bonus.c \
			./bonus/handle_moves.c \
			./bonus/handle2_moves.c \
			./bonus/xpm_to_image.c \
			./bonus/put_image_to_win.c \


MLX = ./minilibx-linux/libmlx_Linux.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FFLAGS = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -rf

OBJECT = $(CFILES:.c=.o)

BOBJECT = $(CBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT) ./src/so_long.h ./ft_printf/ft_printf.h ./get_next_line/get_next_line.h
	@$(CC) $(CFLAGS) $(OBJECT) $(MLX) $(FFLAGS) -o $(NAME)
	@echo "Compiling Successfull"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNAME)

$(BNAME): $(BOBJECT) ./bonus/so_long_bonus.h ./ft_printf/ft_printf.h ./get_next_line/get_next_line.h 
	@$(CC) $(CFLAGS) $(BOBJECT) $(MLX) $(FFLAGS) -o $(BNAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJECT) $(BOBJECT)
	@echo "Object Files Removed Successfully"

fclean: clean
	@$(RM) $(NAME) $(BNAME)
	@echo "Clear"

re: fclean all bonus
