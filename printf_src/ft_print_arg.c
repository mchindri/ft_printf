/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:02:57 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/28 12:09:46 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_number(t_type_format form)
{
	if (ft_strchr("diouxXp",form.conv))
			return (1);
	return (0);
}

int ft_is_string(t_type_format form)
{
	if (form.conv == 's')
		return (1);
	return (0);
}
int ft_is_char(t_type_format form)
{
	if (form.conv == 'c')
		return (1);
	return (0);
}

int ft_is_fractional(t_type_format form)
{
	if (ft_strchr("aAeEgG", form.conv))
		return (1);
	return (0);
}

int ft_is_n(t_type_format form)
{
	if (form.conv == 'n')
		return (1);
	return (0);
}

int	ft_print_arg(t_type_format format, va_list *ap)
{
	if (ft_is_number(format))
		return (ft_print_number(format, ap));
	else if (ft_is_string(format))
		return (ft_print_string(format, ap));
	else if (ft_is_char(format))
		return (ft_print_char(format, ap));
	else if (ft_is_fractional(format))
		return (ft_print_fractional(format, ap));
	else if (format.conv == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (ft_is_n(format))
		return (-1);
	return (-2);
}