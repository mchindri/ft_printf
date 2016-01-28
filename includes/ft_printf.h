/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:50:01 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/28 13:09:31 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"
//
#include   "debug.h"
//
# define CONVERTOR "sSpdDioOuUxXcC%"
# define INTEGER "pdDioOuUxX"

typedef enum	e_exist
{
	NO,
	YES
}				t_exist;

typedef struct	s_type_format
{
	enum
	{
		RIGHT,
		LEFT
	}		pad_side;
	enum
	{
		BLANK,
		ZERO
	}		pad_type;
	enum
	{
		UNSIGNED,
		SIGNED
	}		sign;
	t_exist	thousand_grouped;
	t_exist space;
	t_exist alternate;
	t_exist pointer;
	int		nb_arg;
	int		min_weidth;
	int		precision;
	char	len_mod[2];
	char	conv;
}				t_type_format;


void	AFIS_FORM(t_type_format print_format);


int				ft_printf(const char *format, ...);
char			*ft_find_convertor(char *str);
t_type_format	ft_set_format(char *str, va_list *ap);
int				ft_select_arg(va_list ap, int poz);

int	ft_print_arg(t_type_format format, va_list *ap);

int	ft_print_number(t_type_format form, va_list *ap);
int	ft_print_string(t_type_format form, va_list *ap);
int	ft_print_char(t_type_format form, va_list *ap);
int	ft_print_fractional(t_type_format form, va_list *ap);
char *ft_format_number(char *nbr, t_type_format form, int sign);

char *ft_itoa_base(uintmax_t n, int base);

#endif
