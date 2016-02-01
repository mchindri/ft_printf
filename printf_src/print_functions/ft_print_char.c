/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:29:17 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 15:24:30 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_set_nb(wint_t wc, t_type_format form)
{
	if (form.len_mod[0] == '\0' || wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 65535)
		return (3);
	else if (wc <= 1114111)
		return (4);
	return (0);
}

int	ft_print_char(t_type_format form, va_list *ap)
{
	wint_t	ch;
	int		nb;
	char	c;

	if (NULL == ft_strchr(CONVERTOR, form.conv) || form.conv == '%')
		ch = form.conv;
	else
	{
		ch = (wint_t)va_arg(ap[0], wint_t);
		if (form.len_mod[1] == 'h')
			ch = (wint_t)(unsigned char)ch;//verificat
	}
	nb = ft_set_nb(ch, form);
	if (form.pad_type == BLANK)
		c = ' ';	
	else
		c = '0';
	if (form.pad_side == RIGHT)
	{
		while (nb < form.min_weidth)
		{
			ft_putchar(c);
			nb++;
		}
		if (form.len_mod[0] == '\0')
			ft_putchar(ch);
		else
			ft_putwchar(ch);
	}
	else
	{
		if (form.len_mod[0] == '\0')
			ft_putchar(ch);
		else
			ft_putwchar(ch);
		while (nb < form.min_weidth)
		{
			ft_putchar(' ');
			nb++;
		}
	}
	return (nb);
}
