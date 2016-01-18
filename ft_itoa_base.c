/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:20:48 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/18 14:07:17 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_create_str(char *str, int size, uintmax_t nb, int base)
{
	int aux;

	if (nb == 0)
		str[size] = '0';
	else
		while (nb > 0)
		{
			aux = nb % base;
			if (aux <= 9)
				str[size] = aux + '0';
			else
				str[size] = aux - 10 + 'a';
			nb /= base;
			size--;
		}
}

char *ft_alloc_str(uintmax_t nb, int base)
{
	int			size;
	uintmax_t	nb_cpy;
	char		*str;

	nb_cpy = nb;
	size = 0;
	if (nb == 0)
		size = 1;
	else
		while (nb_cpy > 0)
		{
			nb_cpy /= base;
			size++;
		}
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	size--;
	ft_create_str(str, size, nb, base);
	return (str);
}

char *ft_itoa_base(uintmax_t value, int base)
{
	char		*str;
	char		sign;

	if (base < 2 || base > 16)
		return (NULL);
	str = ft_alloc_str(value, base);
	return (str);
}
