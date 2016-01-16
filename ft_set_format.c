/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:57:04 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/16 15:50:29 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_is_positional_arg(char *str)
{
	//se pot gasi si $ si in alte locuri in afara de la inceput
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
		else if (str[i] == '#')
			form->alternate = YES;
		else if (str[i] == '\'')
			form->thousand_grouped = YES;
		i++;
	}	
}

int				ft_select_param(char *str, int *i, va_list *ap)
{
	int j;
	int n;
	int weidth;

	j = *i + 1;
	while (str[j] && str[j] != '$' && str[j] != '*')
		j++;
	if (str[j] != '$')
	{
		weidth = va_arg(ap[0], int);
		return (weidth);
	}
	n = ft_atoi(str + *i + 1);
	weidth = ft_select_arg(ap[1], n);
	(*i) += j;
	return (weidth);
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
	{
		if (ft_isdigit(str[i]))
		{
			form->min_weidth = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
			i--;
		}
		else if (str[i] == '*')	
			form->min_weidth = ft_select_param(str, &i, ap);
		i++;
	}
}

void	ft_set_precision(char *str, t_type_format *form, va_list *ap)
{
	int n;
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '.')
			i++;
		if (str[i])
		{
			i++;
			if (ft_isdigit(str[i]))
			{
				n = ft_atoi(str + i);
				while(ft_isdigit(str[i]))
					i++;
			}
			else if (str[i] == '*')
				n = ft_select_param(str, &i, ap);
			else
				n = 0;
		}
	}
	form->precision = n;
}

void	ft_set_lenmod(char *str, t_type_format *form)
{
	char	*p;

	p = str + ft_strlen(str) - 1;
	form->conv = *p;
	p--;
	if (p >= str && ft_isalpha(*p))
	{
		(form->len_mod)[0] = *p;
		p--;
	}
	if (p >= str && ft_isalpha(*p))
		(form->len_mod)[1] = *p;
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
	ft_set_lenmod(str, &form);
/*	if (form.conv == 'p')
	{
		form.len_mod[0] = 'l';
		form.len_mod[1] = 0;
		form.alternate = YES;
		form.conv = 'x';
	}*/
	return (form);
}
