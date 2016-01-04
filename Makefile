# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 10:22:09 by mchindri          #+#    #+#              #
#    Updated: 2016/01/04 19:00:00 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
OFILES = ft_printf.o

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

test: re
	gcc main.c -L . -lftprintf ft_strcpy.c ft_strdup.c ft_strlen.c
	./a.out
