/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 08:43:51 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/22 07:12:54 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_in_printf_uint(char *str_ui, t_flags flags)
{
	int output;

	output = 0;
	if (flags.dot >= 0)
		output += ft_printf_width(flags.dot - 1, ft_strlen(str_ui) - 1, 1);
	output += ft_printf_preci(str_ui, ft_strlen(str_ui));
	return (output);
}

static int	ft_in_printf_uint(char *str_ui, t_flags flags)
{
	int output;

	output = 0;
	if (flags.minus == 1)
		output += ft_in_in_printf_uint(str_ui, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_ui))
		flags.dot = ft_strlen(str_ui);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		output += ft_printf_width(flags.width, 0, 0);
	}
	else
		output += ft_printf_width(flags.width,
		ft_strlen(str_ui), flags.zero);
	if (flags.minus == 0)
		output += ft_in_in_printf_uint(str_ui, flags);
	return (output);
}

int			ft_printf_uint(unsigned int ui, t_flags flags)
{
	char	*str_ui;
	int		output;

	output = 0;
	if (flags.dot == 0 && ui == 0)
	{
		output += ft_printf_width(flags.width, 0, 0);
		return (output);
	}
	str_ui = ft_uitoa_base(ui, 10);
	output += ft_in_printf_uint(str_ui, flags);
	free(str_ui);
	return (output);
}
