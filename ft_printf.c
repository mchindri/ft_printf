/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:48:34 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/04 16:00:49 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_procent(char *p, int *printd_ch)
{
	int		ok;
	char	*q;

	while (*p)
	{
		q = CONVERTOR;
		ok = 0;
		while (*q && ok == 0)
			if (*q == *p)
				ok = 1;
			else
				q++;
		if (ok = 1)
			return (p);
		write(1, p, 1);
		(*printed_ch)++;
		p++;
	}
	return (NULL);
}

char	*ft_find_form_convertor(char *p)
{

}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*p;
	char	*q;
	char	*conv_spec;
	int		printed_ch;

	printed_ch = 0;
	va_start(ap, format);
	p = (char *)format;
	while (1)
	{
		p = ft_find_procent(p, &printed_ch);
		if (p == NULL)
			break;
		q = ft_find_form_convert(p + 1);
		if (q == NULL)
			break;
		conv_spec = (char *)malloc(q - p + 1);
		ft_strncpy(conv_spec, p, q - p);
	}
	va_end(ap);
	return (1);
}
