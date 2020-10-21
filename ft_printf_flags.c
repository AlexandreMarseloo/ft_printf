/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:29:55 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/10 08:09:23 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.zero = 0;
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			ft_flag_dot(const char *input, int i,
			t_flags *flags, va_list args)
{
	flags->dot = 0;
	i++;
	if (input[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		while (ft_isdigit(input[i]))
			flags->dot = (flags->dot * 10) + (input[i++] - '0');
	}
	return (i);
}
