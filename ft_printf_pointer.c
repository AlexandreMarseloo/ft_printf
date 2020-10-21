/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:06:24 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/10 10:22:36 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_printf_pointer(char *pointer)
{
	int output;

	output = 0;
	output += ft_printf_preci("0x", 2);
	output += ft_printf_preci(pointer, ft_strlen(pointer));
	return (output);
}

static char	*ft_special_case(t_flags flags)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (flags.dot + 1))))
		return (0);
	while (i < flags.dot)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int			ft_printf_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		output;

	output = 0;
	if (ull == 0 && flags.dot >= 0)
		pointer = ft_special_case(flags);
	else
		pointer = ft_ulltoa_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if (flags.minus == 1)
		output += ft_in_printf_pointer(pointer);
	output += ft_printf_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		output += ft_in_printf_pointer(pointer);
	free(pointer);
	return (output);
}
