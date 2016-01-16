/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:44:29 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/16 16:00:31 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_convertor(char ch)
{
	char *conv;

	conv = CONVERTOR;
	while (*conv)
		if (*conv == ch)
			return (1);
		else
			conv++;
	return (0);
}

static char	*ft_copy_convertor(char *p, char **copy)
{
	char	*aux;
	int		i;

	aux = p;
	while (!ft_is_convertor(*aux))
		aux++;
	*copy  = (char *)malloc(sizeof(char) * (aux - p + 2));
	(*copy)[aux - p] = '\0';
	i = 0;
	while (p <= aux)
	{
		(*copy)[i] = *p;
		p++;
		i++;
	}
	return (p);
}


static char	*ft_write_to_procent(char *str, int *printed_ch)
{
	while (*str != '%' && *str)
	{
		write(1, str, 1);
		str++;
		(*printed_ch)++;
	}
	if (*str)
		return (str + 1);
	return (NULL);
}

int			ft_printf(const char *format, ...)
{
	int				printed_ch;
	va_list			ap[2];
	t_type_format	print_format;
	char			*p;
	char			*str;

	printed_ch = 0;
	p = ft_write_to_procent((char *)format, &printed_ch);
	va_start(ap[0], format);
	va_copy(ap[1], ap[0]);
	while (p)
	{
		p = ft_copy_convertor(p, &str);
		print_format = ft_set_format(str, ap);
	//	AFIS_FORM(print_format);
		printed_ch += ft_print_arg(print_format, ap);
		p = ft_write_to_procent(p, &printed_ch);
	}
	va_end(ap[1]);
	va_end(ap[0]);
	return (printed_ch);
}
