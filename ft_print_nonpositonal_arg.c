/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nonpositonal_arg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:03:36 by mchindri          #+#    #+#             */
/*   Updated: 2016/01/09 16:56:39 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_nonpositional_arg(char *str, t_type_format spec, va_list *ap)
{
	int nb;

	if (spec.len_mod[0] == '\0')
	{
		if (ft_strch(spec.conv, INTEGER))
			ft_print_number(spec, *ap);
		else if (ft_strch(spec.conv, STR))
			ft_print_str
	}
	else if (spec.len_mod[1] == '\0')
	{
	}
	else
	{
	}
}
