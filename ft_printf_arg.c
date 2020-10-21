/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:47:38 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/10 07:19:55 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_arg(int c, t_flags flags, va_list args)
{
	int output;

	output = 0;
	if (c == 'c')
		output += ft_printf_char(va_arg(args, int), flags);
	else if (c == 's')
		output += ft_printf_str(va_arg(args, char *), flags);
	else if (c == 'p')
		output += ft_printf_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		output += ft_printf_int(va_arg(args, int), flags);
	else if (c == 'u')
		output += ft_printf_uint(va_arg(args, unsigned int),
		flags);
	else if (c == 'x')
		output += ft_printf_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		output += ft_printf_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		output += ft_printf_percent(flags);
	return (output);
}
