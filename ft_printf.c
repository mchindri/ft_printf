/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:44:29 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/06 12:11:21 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_write_to_procent(char *str, int *printed_ch)
{
	while (*str != '%' && *str)
	{
		write(1, str, 1);
		str++;
		(*printed_ch)++;
	}
	if (*str)
		return (str);
	return (NULL);
}

int			ft_printf(const char *format, ...)
{
	int		printed_ch;
	va_list	ap;
	char	*p;

	printed_ch = 0;
	p = ft_write_to_procent((char *)format, &printed_ch);
	va_start(ap, format);
	while (p)
	{
		if (ft_is_positional_arg(p))
			p = ft_print_positional_arg(p, &printed_ch);
		else
			p = ft_print_nonpositional_arg(p ,&printed_ch, &ap);
		p = ft_write_to_procent(p, &printed_ch);
	}
	va_end(ap);
	return (printed_ch);
}
