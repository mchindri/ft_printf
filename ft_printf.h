/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:50:01 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/04 15:55:14 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define CONVERTOR "sSpdDioOuUxXcC%"

typedef struct	s_type_format
{
	char	*flags;
	int		min_weidth;
	int		precision;
	char	length_modefier[2];
}				t_type_format;

int	ft_printf(const char *format, ...);

#endif
