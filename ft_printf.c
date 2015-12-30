/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:48:34 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/30 13:52:38 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*p;
	char	*q;
	char	*conv_spec;

	va_start(ap, format);
	p = (char *)format;
	while (1)
	{
		p = ft_find_procent(p);
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
