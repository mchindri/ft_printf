/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:14:35 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/28 16:19:29 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strwlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i++]);
	return (i);
}

int		ft_wchar_len(wchar_t wc)
{
	if (wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 65535)
		return (3);
	else if (wc <= 1114111)
		return (4);
	return (0);

}

int		ft_putwstr_(wchar_t *str)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		nb += ft_wchar_len(str[i]);
		i++;
	}
	return (nb);
}

wchar_t	*ft_strwdup(wchar_t *s1)
{
	wchar_t *copy;
	wchar_t *p;
	wchar_t *q;

	if (s1 == NULL)
		return (NULL);
	copy = (wchar_t *)malloc(sizeof(wchar_t) *(ft_strwlen(s1) + 1));
	p = (wchar_t *)s1;
	q = copy;
	while (*p != '\0')
	{
		*q = *p;
		q++;
		p++;
	}
	*q = '\0';
	return (copy);
}
int		ft_print_string(t_type_format form, va_list *ap)
{
	wchar_t *w_str;
	char	*str;
	int		nb;
	char	c;

	nb = 0;
	if (form.len_mod[0] == '\0')
	{
		str = ft_strdup((char *)va_arg(ap[0], char *));
		if (str == 0)
		{
			ft_putstr("(null)");
			return (6);
		}
		nb = ft_strlen(str);
		if (form.precision >= 0)
			str[form.precision] = '\0';
		nb = ft_strlen(str);
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
			ft_putstr(str);
		}
		else
		{
			ft_putstr(str);
			while (nb < form.min_weidth)
			{
				ft_putchar(' ');
				nb++;
			}
		}
	}
	else
	{
		w_str = ft_strwdup((wchar_t *)va_arg(ap[0], wchar_t *));
		if (w_str == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		if (form.precision >= 0)
			w_str[form.precision] = '\0';
		nb = ft_strwlen(w_str);
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
			nb += ft_putwstr_(w_str);
		}
		else
		{
			nb += ft_putwstr_(w_str);
			while (nb < form.min_weidth)
			{
				ft_putchar(' ');
				nb++;
			}
		}
	}
	return (nb);
}
