/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 10:16:55 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 14:08:59 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define FORMAT "{%+03d}", 0

int main()
{
	int sa=324;
	char str[100] = "%$2hhd";
	int n = 1;
   	int a,b;	
	printf("printf:\n");
	a = printf(FORMAT);
	printf("\t%d",a);
	printf("\nft_printf\n");
	b = ft_printf(FORMAT);
	printf("\t%d", b);
	printf("\n");

//	ft_printf(FORMAT);
//	STR("\n");
	return (0);
}
