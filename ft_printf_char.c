/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:12:03 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/01 21:19:23 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_char(char c, t_flags flags)
{
	int output;

	output = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	output = ft_printf_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (output + 1);
}
