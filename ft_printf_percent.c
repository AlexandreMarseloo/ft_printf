/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:26:42 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/01 22:35:16 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_percent(t_flags flags)
{
	int output;

	output = 0;
	if (flags.minus == 1)
		output += ft_putchar('%');
	output += ft_printf_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		output += ft_putchar('%');
	return (output);
}
