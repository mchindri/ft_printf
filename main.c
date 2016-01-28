/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 10:16:55 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/28 13:44:00 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define FORMAT "%c", 200 

int main()
{
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
	return (0);
}
