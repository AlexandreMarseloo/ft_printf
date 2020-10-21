# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 09:20:37 by almarsel          #+#    #+#              #
#    Updated: 2020/10/01 22:20:07 by almarsel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_printf_arg.c \
		ft_printf_width.c \
		ft_printf_preci.c \
		ft_printf_str.c \
		ft_printf_char.c \
		ft_printf_pointer.c \
		ft_printf_int.c \
		ft_printf_uint.c \
		ft_printf_percent.c \
		ft_printf_hexa.c \
		ft_printf_flags.c \
		ft_printf_utils.c

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re