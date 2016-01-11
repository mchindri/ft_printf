# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 10:22:09 by mchindri          #+#    #+#              #
#    Updated: 2016/01/11 15:51:22 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_set_format.c ft_select_arg.c \
	  aux.c 

OFILES = ft_printf.o ft_set_format.o ft_select_arg.o \
		 aux.o

DEBUG = -I debug

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c -I libft $(FLAGS) $(SRC) $(DEBUG)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

test: re
	gcc main.c -L . -lftprintf -L ./libft -lft -I libft $(DEBUG)
	./a.out
