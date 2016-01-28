/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:32:21 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/27 18:03:27 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	AFIS_FORM(t_type_format p)
{
	STR("\nPad_side: ")
	if (p.pad_side == RIGHT)
		STR("Right")
	else
		STR("Left")

	STR("\nPad_type: ")
	if (p.pad_type == BLANK)
		STR("Blank")
	else
		STR("Zero")

	STR("\nSign: ")
	if (p.sign == SIGNED)
		STR("Signed")
	else
		STR("Unsigned")

	STR("\nThousand_grouped: ")
	if (p.thousand_grouped == YES)
		STR("Yes")
	else
		STR("NO")
	
	STR("\nPointer: ")
	if (p.pointer == YES)
		STR("Yes")
	else
		STR("NO")

	STR("\nSpace: ")
	if (p.space == YES)
		STR("Yes")
	else
		STR("NO")

	STR("\nAlternate: ")
	if (p.alternate == YES)
		STR("Yes")
	else
		STR("NO")
	
	STR("\nNb_arg: ");
	ft_putnbr(p.nb_arg);

	STR("\nMin_weidth: ");
	ft_putnbr(p.min_weidth);

	STR("\nPrecision: ");
	ft_putnbr(p.precision);

	STR("\nLen_mod: ");
	ft_putchar(p.len_mod[0]);
	ft_putchar(p.len_mod[1]);

	STR("\nConvertor: ");
	ft_putchar(p.conv);

	STR("\n");
}
