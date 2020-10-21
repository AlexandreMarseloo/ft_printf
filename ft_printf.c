/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:23:59 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/08 08:18:05 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_flag_parse(const char *input, int i,
				t_flags *flags, va_list args)
{
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && !ft_is_in_type_list(input[i])
		&& !ft_is_in_flags_list(input[i]))
			break ;
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, args);
		if (input[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (input[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(input[i]))
			*flags = ft_flag_digit(input[i], *flags);
		if (ft_is_in_type_list(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_start_printf(const char *input, va_list args)
{
	int			i;
	t_flags		flags;
	int			output;

	i = 0;
	output = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!input[i])
			break ;
		else if (input[i] == '%' && input[i + 1])
		{
			i = ft_flag_parse(input, i + 1, &flags, args);
			if (ft_is_in_type_list(input[i]))
				output += ft_printf_arg(flags.type, flags, args);
			else if (input[i])
				output += ft_putchar(input[i]);
		}
		else if (input[i] != '%')
			output += ft_putchar(input[i]);
		i++;
	}
	return (output);
}

int			ft_printf(const char *input, ...)
{
	va_list		args;
	int			output;

	output = 0;
	va_start(args, input);
	output += ft_start_printf(input, args);
	va_end(args);
	return (output);
}
