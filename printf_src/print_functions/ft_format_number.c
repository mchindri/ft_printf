/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:50 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 14:09:01 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_unsigned(char ch)
{
	if (ch == 'o' || ch == 'u' || ch == 'x' || ch == 'U' || ch == 'X')
		return (1);
	return (0);
}

int ft_calc_size(char *nbr, t_type_format form, int sign)
{
	int size;
	int nb_size;

	size = ft_strlen(nbr); 
	//thousand_group
	nb_size = size;
	if (((form.sign == SIGNED || form.space == YES) && 
		!ft_is_unsigned(form.conv)) || sign == 1)
		size++;
	if (form.alternate == YES && (nbr[0] != '0' || form.pointer == YES))
	{
		if (form.conv == 'X' || form.conv == 'x' || form.pointer == YES)
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
//	int		signed_;

//	AFIS_FORM(form);
	size = ft_calc_size(nbr, form, sign);
	if (NULL == (formated_nbr = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(formated_nbr, ' ', size);
	formated_nbr[size] = 0;
	nbr_len = ft_strlen(nbr);
	i = ft_strlen(formated_nbr) - nbr_len;
	if (nbr[0] == '0' && form.precision == 0)
		ft_strcpy(formated_nbr + i, "");
	else
		ft_strcpy(formated_nbr + i, nbr);
	j = 0;
	
	/*if (form.sign == SIGNED || sign == 0)
		signed_ = 1;
	else
		signed_ = 0;*/
	while (nbr_len + j < form.precision ||
			(form.precision < 0 && form.pad_type == ZERO &&
			 form.pad_side == RIGHT && nbr_len + j + sign < form.min_weidth))
		if (form.alternate == YES && form.pad_type == ZERO && i - j - 1 == 1)
			break;
		else
			formated_nbr[i - j++ - 1] = '0';
	i -= j + 1;
	if (form.alternate == YES && (!(form.conv == 'o' &&
					formated_nbr[i + 1] == '0') || form.pointer == YES))
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
	else if (form.sign == SIGNED && !ft_is_unsigned(form.conv))
		formated_nbr[i--] = '+';
	else if (form.space == YES)
		i--;
	if (form.pad_side == LEFT && i >= 0)
	{
		ft_strcpy(formated_nbr, formated_nbr + i + 1);
		ft_memset(formated_nbr + ft_strlen(formated_nbr), ' ', i + 1);
	}
	free(nbr);
	return (formated_nbr);
}
