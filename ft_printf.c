/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:48:34 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/04 19:00:49 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}

char	*ft_find_procent(char *p, int *printed_ch)
{
	while (*p != '%' && *p)
	{
		write(1, p, 1);
		p++;
		(*printed_ch)++;
	}
	if (*p)
		return (p);
	return (NULL);
}

char	*ft_find_form_convertor(char *p)
{
	char	*q;

	while (*p)
	{
		q = CONVERTOR;
		while (*q)
			if (*q == *p)
				return (p);
			else
				q++;
		p++;
	}
	return (NULL);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*p;
	char	*q;
	//char	*conv_spec;
	int		printed_ch;

	printed_ch = 0;
	va_start(ap, format);
	p = ft_strdup(format);
	while (1)
	{
		p = ft_find_procent(p, &printed_ch);
		if (p == NULL)
			break;
		q = ft_find_form_convertor(p + 1);
		if (q == NULL)
			break;
		//conv_spec = (char *)malloc(q - p + 1);
		ft_strcpy(p, q + 1);
	}
	va_end(ap);
	return (printed_ch);
}
