# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enorie <enorie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:34:46 by root              #+#    #+#              #
#    Updated: 2024/01/02 16:01:38 by enorie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = commands.c ft_check_error.c ft_lists.c ft_sort_utils.c ft_sort.c \
ft_sort_utils2.c ft_split.c ft_utils.c ft_utils2.c push_swap.c


FLAG = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		cc $(FLAG) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
