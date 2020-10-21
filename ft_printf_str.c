/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:57:30 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/01 22:38:41 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_in_printf_str(char *str, t_flags flags)
{
	int output;

	output = 0;
	if (flags.dot >= 0)
	{
		output += ft_printf_width(flags.dot, ft_strlen(str), 0);
		output += ft_printf_preci(str, flags.dot);
	}
	else
	{
		output += ft_printf_preci(str, ft_strlen(str));
	}
	return (output);
}

int				ft_printf_str(char *str, t_flags flags)
{
	int output;

	output = 0;
	if (!str)
		str = "(null)\0";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		output += ft_in_printf_str(str, flags);
	if (flags.dot >= 0)
		output += ft_printf_width(flags.width, flags.dot, 0);
	else
		output += ft_printf_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		output += ft_in_printf_str(str, flags);
	return (output);
}
