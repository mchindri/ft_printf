/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 10:16:55 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/16 16:02:55 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define FORMAT "%c",4,4,10

int main()
{
	char str[100] = "%$2hhd";
	printf("printf:\n");
	printf(FORMAT);
	printf("\nft_printf\n");
	ft_printf(FORMAT);
	return (0);
}
