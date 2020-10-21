/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:47:19 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/11 18:55:27 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_in_printf_int(char *str_i, int i, t_flags flags)
{
	int output;

	output = 0;
	if (i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		output += ft_printf_width(flags.dot - 1, ft_strlen(str_i) - 1, 1);
	output += ft_printf_preci(str_i, ft_strlen(str_i));
	return (output);
}

static int	ft_in_printf_int(char *str_i, int i, t_flags flags)
{
	int output;

	output = 0;
	if (flags.minus == 1)
		output += ft_in_in_printf_int(str_i, i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_i))
		flags.dot = ft_strlen(str_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		output += ft_printf_width(flags.width, 0, 0);
	}
	else
		output += ft_printf_width(flags.width, ft_strlen(str_i), flags.zero);
	if (flags.minus == 0)
		output += ft_in_in_printf_int(str_i, i, flags);
	return (output);
}

static char	*ft_to_itoa(int i, int sign, t_flags flags)
{
	char	*str_i;

	if (i == -2147483648)
	{
		if (flags.dot < 0 && flags.zero == 0)
			str_i = ft_strdup("-2147483648");
		else
			str_i = ft_strdup("2147483648");
	}
	else
		str_i = ft_itoa(sign * i);
	return (str_i);
}

int			ft_printf_int(int i, t_flags flags)
{
	char	*str_i;
	int		sign;
	int		output;

	sign = 1;
	output = 0;
	if (flags.dot == 0 && i == 0)
		return (ft_printf_width(flags.width, 0, 0));
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot < 0)
			ft_putchar('-');
		sign = -1;
		flags.width--;
		output++;
	}
	str_i = ft_to_itoa(i, sign, flags);
	output += ft_in_printf_int(str_i, i, flags);
	free(str_i);
	return (output);
}
