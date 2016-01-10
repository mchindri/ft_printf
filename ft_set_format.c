/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:57:04 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/10 16:39:17 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_is_positional_arg(char *str)
{
	while (*str)
	{
		if (*str == '$')
			return (1);
		if (*str == '*')
			return (0);
		str++;
	}
	return (0);
}

void	ft_set_flags(char *str, t_type_format *form)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			form->pad_type = ZERO;
		if (ft_isdigit(str[i - 1]))
			break;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			form->pad_side = LEFT;
		else if (str[i] == ' ')
			form->space = YES;
		else if (str[i] == '+')
			form->sign = SIGNED;
		else if (str[i] == '\'')
			form->thousand_grouped = YES;
		i++;
	}	
}

int				ft_find_weidth_in_ap(char *str, int *weidth, va_list *ap)
{
	int j;
	int n;

	j = 0;
	while (str[j] && str[j] != '$' && str[j] != '*')
		j++;
	if (str[j] == '*')
	{
		*weidth = va_arg(ap[1], int);
		return (1);
	}
	n = ft_atoi(str);
	*weidth = ft_select_arg(ap[2], n);
	return (j);
}

void			ft_set_weidth(char *str, t_type_format *form, va_list *ap)
{
	int i;

	if (form->nb_arg != 0)
	{
		while (*str != '$')
			str++;
		str++;
	}
	i = 0;
	while (str[i] && str[i] != '.')
		if (ft_isdigit(str[i]))
		{
			form->min_weidth = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] == '*')
			i += ft_find_weidth_in_ap(str + i + 1, &(form->min_weidth), ap);
}

t_type_format	ft_set_format(char *str,  va_list *ap)
{
	t_type_format form;

	ft_bzero(&form, sizeof(t_type_format));
	if (ft_is_positional_arg(str))
		form.nb_arg = ft_atoi(str);
	ft_set_flags(str, &form);
	ft_set_weidth(str, &form, ap);
	ft_set_precision(str, &form, ap);
	return (form);
}
