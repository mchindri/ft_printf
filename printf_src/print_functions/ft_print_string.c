/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:14:35 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/28 13:43:58 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_type_format form, va_list *ap)
{
	wchar_t *str;

	str = (wchar_t *)va_arg(wchar_t *);	
	return (0);
}
