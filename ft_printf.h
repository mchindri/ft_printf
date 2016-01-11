/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:50:01 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/11 15:54:04 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

#include   "debug.h"

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

#endif
