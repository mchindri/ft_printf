/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 10:16:55 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/18 17:38:13 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define FORMAT "%-#10.5x", 342 

int main()
{
	char str[100] = "%$2hhd";
	int n = 
	printf("printf:\n");
	printf(FORMAT);
	printf("\nft_printf\n");
	ft_printf(FORMAT);
	printf("\n");
	return (0);
}
