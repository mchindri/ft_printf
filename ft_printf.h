/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:50:01 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/06 12:13:10 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define CONVERTOR "sSpdDioOuUxXcC%"

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);

char	*ft_find_convertor(char *str);

typedef struct	s_type_format
{
	enum
	{
		LEFT_PAD,
		RIGHT_PAD
	}		pad_side;
	enum
	{
		BLANK_PAD,
		ZERO_PAD
	}		pad_type;
	enum
	{
		UNSIGNED,
		SIGNED
	}		sign;
	enum
	{
		YES,
		NO
	}		thousand_gruped;
	int		min_weidth;
	int		precision;
	char	length_modifier;
}				t_type_format;

int	ft_printf(const char *format, ...);

#endif
