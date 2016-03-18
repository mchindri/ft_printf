/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:08:25 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/18 10:24:42 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b)
{
	void *aux;

	ft_memcpy(aux, a, sizeof(a));
	ft_memcpy(a, b, sizeof(b));
	ft_memcpy(b, aux, sizeof(aux));
}
