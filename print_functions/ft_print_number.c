/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:26:25 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/18 17:38:10 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_conv_unsigned(char *len_mod, va_list *ap)
{
	uintmax_t	n;

	if (len_mod[0] == 'h')
		n = (uintmax_t)va_arg(ap[0], unsigned int); //unsigned short
	else if (len_mod[0] == 'l')
		n = (uintmax_t)va_arg(ap[0], unsigned long);
	else if (len_mod[0] == 'l' && len_mod[1] == 'l')
		n = (uintmax_t)va_arg(ap[0], unsigned long long);
	else if (len_mod[0] == 'j')
		n = (uintmax_t)va_arg(ap[0], uintmax_t);
	else if (len_mod[0] == 'z')
		n = (uintmax_t)va_arg(ap[0], size_t);
	else
		n = (intmax_t)va_arg(ap[0], unsigned);
	return (n);
}

uintmax_t	ft_conv_signed(char *len_mod, va_list *ap, int *sign)
{
	uintmax_t	n;
	intmax_t	n_neg;
	short a;

	if (len_mod[0] == 'h')
		n_neg = (intmax_t)va_arg(ap[0], int); //short
	else if (len_mod[0] == 'l')
		n_neg = (intmax_t)va_arg(ap[0], long);
	else if (len_mod[0] == 'l' && len_mod[1] == 'l')
		n_neg = (intmax_t)va_arg(ap[0], long long);
	else if (len_mod[0] == 'j')
		n_neg = (intmax_t)va_arg(ap[0], intmax_t);
	else if (len_mod[0] == 'z')
		n_neg = (intmax_t)va_arg(ap[0], intmax_t);
	else
		n_neg = (intmax_t)va_arg(ap[0], int);
	if (n_neg < 0)
	{
		n = n_neg * (-1);
		*sign = 1;
		return (n);
	}
	*sign = 0;
	n = n_neg;
	return (n);
}

void	ft_upper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int ft_calc_size(char *nbr, t_type_format form, int sign)
{
	int size;
	int nb_size;

	size = ft_strlen(nbr); //thousand_group
	nb_size = size;
	if (form.sign == SIGNED || form.space == YES || sign == 1)
		size++;
	if (form.alternate == YES)
	{
		if (form.conv == 'X' || form.conv == 'x')
			size += 2;
		else
			size++;
	}
	if (form.precision > nb_size)
		size += form.precision - nb_size;
	if (form.min_weidth > size)
		size = form.min_weidth;
	return (size);
}

char	*ft_format_number(char *nbr, t_type_format form, int sign)
{
	char	*formated_nbr;
	int		nbr_len;
	int		size;
	int		i;
	int		j;

	size = ft_calc_size(nbr, form, sign);
	if (NULL == (formated_nbr = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(formated_nbr, ' ', size);
	formated_nbr[size] = 0;
	nbr_len = ft_strlen(nbr);
	i = ft_strlen(formated_nbr) - nbr_len;
	ft_strcpy(formated_nbr + i, nbr);
	j = 0;
	while (nbr_len + j < form.precision ||
				(form.precision == 0 && form.pad_type == ZERO &&
				 form.pad_side == RIGHT && nbr_len + j < form.min_weidth))
		formated_nbr[i - j++ - 1] = '0';
	i -= j + 1;
	if (form.alternate == YES &&
			!(form.conv == 'o' && formated_nbr[i + 1] == '0'))
	{
		if (form.conv == 'x')
			formated_nbr[i--] = 'x';
		else if (form.conv == 'X')
			formated_nbr[i--] = 'X';
		if (ft_strchr("xXo", form.conv))
			formated_nbr[i--] = '0';
	}
	if (sign == 1)
		formated_nbr[i--] = '-';
	else if (form.sign == SIGNED)
		formated_nbr[i--] = '+';
	else if (form.space == YES)
		i--;
	if (form.pad_side == LEFT && i >= 0)
	{
		STR(formated_nbr)
		ft_strcpy(formated_nbr, formated_nbr + i + 1);
		ft_memset(formated_nbr + ft_strlen(formated_nbr), ' ', i + 1);
	}
	free(nbr);
	return (formated_nbr);
}

int		ft_print_number(t_type_format form, va_list *ap)
{
	//ft_putstr("Is number\n");
	uintmax_t	n;
	int			sign;
	char		*str;
	int			nbr;

	if (ft_strchr("diDI", form.conv))
		n = ft_conv_signed(form.len_mod, ap, &sign);
	else
	{
		sign = 0;
		n = ft_conv_unsigned(form.len_mod, ap);
	}
//	dprintf(2, "%ju\n",n);
	if (ft_strchr("idu", form.conv))
		str = ft_itoa_base(n, 10);
	else if (form.conv == 'o' || form.conv == 'O')
		str = ft_itoa_base(n, 8);
	else if (form.conv == 'X')
	{
		str = ft_itoa_base(n, 16);
		ft_upper(str);
	}
	else
		str =ft_itoa_base(n, 16);
//	str = ft_format_number(str, form ,sign);
	if (str == NULL)
		return (-1);
	ft_putstr(str);
	//free(str);
	return (ft_strlen(str));
}
