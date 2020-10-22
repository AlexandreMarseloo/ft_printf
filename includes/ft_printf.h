/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:15:30 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/22 07:13:31 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	char			type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_printf_arg(int c, t_flags flags, va_list args);
int					ft_printf_width(int width, int minus, int has_zero);
int					ft_printf_preci(char *str, int prec);
int					ft_printf_char(char c, t_flags flags);
int					ft_printf_str(char *str, t_flags flags);
int					ft_printf_int(int i, t_flags flags);
int					ft_printf_percent(t_flags flags);
int					ft_printf_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_printf_uint(unsigned int unsi, t_flags flags);
int					ft_printf_pointer(unsigned long long pointer,
					t_flags flags);
int					ft_is_in_type_list(int c);
int					ft_is_in_flags_list(int c);
t_flags				ft_init_flags(void);
int					ft_flag_dot(const char *save, int start,
					t_flags *flags, va_list args);
t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);

#endif
