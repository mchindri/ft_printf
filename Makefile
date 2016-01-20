# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchindri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 10:22:09 by mchindri          #+#    #+#              #
#    Updated: 2016/01/20 16:12:13 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_set_format.c ft_select_arg.c ft_print_arg.c\
	  print_functions/ft_print_number.c \
	  print_functions/ft_print_string.c \
	  print_functions/ft_print_char.c \
	  print_functions/ft_print_fractional.c \
	  ft_itoa_base.c \
	  aux.c
FT_SRC = ft_atoi.c		\
		ft_bzero.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_memalloc.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memdel.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar.c	\
		ft_putchar_fd.c\
		ft_putendl.c	\
		ft_putendl_fd.c\
		ft_putnbr.c	\
		ft_putnbr_fd.c	\
		ft_putstr.c	\
		ft_putstr_fd.c	\
		ft_strcat.c	\
		ft_strchr.c	\
		ft_strclr.c	\
		ft_strcmp.c	\
		ft_strcpy.c	\
		ft_strdel.c	\
		ft_strdup.c	\
		ft_strequ.c	\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlen.c	\
		ft_strmap.c	\
		ft_strmapi.c	\
		ft_strncat.c	\
		ft_strncmp.c	\
		ft_strncpy.c	\
		ft_strnequ.c	\
		ft_strnew.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strsplit.c	\
		ft_strstr.c	\
		ft_strsub.c	\
		ft_strtrim.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_lstnew.c	\
		ft_lstdelone.c	\
		ft_lstdel.c	\
		ft_lstadd.c	\
		ft_lstiter.c	\
		ft_lstmap.c	\
		ft_absd.c		\
		ft_absi.c		\
		ft_powi.c		\
		ft_strrev.c	\
		ft_swap.c		\
		ft_sqrt.c


OFILES = ft_printf.o ft_set_format.o ft_select_arg.o ft_print_arg.o\
		 ft_print_number.o \
		 ft_print_string.o \
		 ft_print_char.o \
		 ft_print_fractional.o \
		 ft_itoa_base.o\
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
