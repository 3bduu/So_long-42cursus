# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:32:58 by abenlahb          #+#    #+#              #
#    Updated: 2023/01/20 11:55:12 by abenlahb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCB = bonus/so_long_bonus.c bonus/our_map_bonus.c bonus/libft/ft_bzero.c bonus/libft/ft_calloc.c bonus/libft/ft_split.c bonus/libft/ft_substr.c  \
bonus/libft/get_next_line.c bonus/libft/ft_strdup.c bonus/libft/ft_strjoin.c bonus/libft/ft_strlen.c bonus/player_hooks_bonus.c bonus/valid_path_bonus.c \
bonus/libft/ft_printf.c bonus/libft/ft_put_address.c bonus/libft/ft_put_hex_maj_nbr.c bonus/libft/ft_put_hex_min_nbr.c bonus/libft/ft_put_sign.c \
bonus/libft/ft_put_uns_nbr.c bonus/libft/ft_putchar.c bonus/libft/ft_putnbr.c bonus/libft/ft_putstr.c bonus/free_map_bonus.c bonus/cheak_map_bonus.c bonus/draw_map_bonus.c bonus/player_move_bonus.c \
bonus/libft/ft_itoa.c bonus/animation_collect.c

SRC = src/so_long.c src/our_map.c bonus/libft/ft_bzero.c bonus/libft/ft_calloc.c bonus/libft/ft_split.c bonus/libft/ft_substr.c  \
bonus/libft/get_next_line.c bonus/libft/ft_strdup.c bonus/libft/ft_strjoin.c bonus/libft/ft_strlen.c src/player_hooks.c src/valid_path.c \
bonus/libft/ft_printf.c bonus/libft/ft_put_address.c bonus/libft/ft_put_hex_maj_nbr.c bonus/libft/ft_put_hex_min_nbr.c bonus/libft/ft_put_sign.c \
bonus/libft/ft_put_uns_nbr.c bonus/libft/ft_putchar.c bonus/libft/ft_putnbr.c bonus/libft/ft_putstr.c src/free_map.c src/cheak_map.c src/draw_map.c src/player_move.c \
bonus/libft/ft_itoa.c

OBJB = $(SRCB:.c=.o)
OBJ = $(SRC:.c=.o)
NAME = so_long
CC = cc

all : $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus: $(OBJB)
	$(CC) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c
	$(CC)  -Wall -Wextra -Werror -Imlx -c $< -o $@
clean:
	rm -rf $(OBJ) $(OBJB)
fclean:clean
	rm -rf $(NAME)

re: fclean all 