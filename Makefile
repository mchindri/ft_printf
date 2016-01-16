# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 10:22:09 by mchindri          #+#    #+#              #
#    Updated: 2016/01/16 15:58:57 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_set_format.c ft_select_arg.c ft_print_arg.c\
		print_functions/ft_print_number.c \
		print_functions/ft_print_string.c \
		print_functions/ft_print_char.c \
		print_functions/ft_print_fractional.c \
	  aux.c

OFILES = ft_printf.o ft_set_format.o ft_select_arg.o ft_print_arg.o\
		ft_print_number.o \
		ft_print_string.o \
		ft_print_char.o \
		ft_print_fractional.o \
		 aux.o

DEBUG = -I debug

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c -I libft $(SRC) $(DEBUG) -I .
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME) a.out
	@make -C libft fclean

re: fclean all

test: re
	gcc main.c -L . -lftprintf -L ./libft -lft -I libft $(DEBUG)
	./a.out
