/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:39:54 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/04 16:12:49 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_in_in_printf_hexa(char *hexa, t_flags flags)
{
	int output;

	output = 0;
	if (flags.dot >= 0)
		output += ft_printf_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	output += ft_printf_preci(hexa, ft_strlen(hexa));
	return (output);
}

static int		ft_in_printf_hexa(char *hexa, t_flags flags)
{
	int output;

	output = 0;
	if (flags.minus == 1)
		output += ft_in_in_printf_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		output += ft_printf_width(flags.width, 0, 0);
	}
	else
		output += ft_printf_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		output += ft_in_in_printf_hexa(hexa, flags);
	return (output);
}

int				ft_printf_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		output;

	output = 0;
	if (flags.dot == 0 && ui == 0)
	{
		output += ft_printf_width(flags.width, 0, 0);
		return (output);
	}
	hexa = ft_uitoa_base(ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	output += ft_in_printf_hexa(hexa, flags);
	free(hexa);
	return (output);
}
