# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 09:20:37 by almarsel          #+#    #+#              #
#    Updated: 2020/10/22 07:16:51 by almarsel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  sources/ft_printf.c \
		sources/ft_printf_arg.c \
		sources/ft_printf_width.c \
		sources/ft_printf_preci.c \
		sources/ft_printf_str.c \
		sources/ft_printf_char.c \
		sources/ft_printf_pointer.c \
		sources/ft_printf_int.c \
		sources/ft_printf_uint.c \
		sources/ft_printf_percent.c \
		sources/ft_printf_hexa.c \
		sources/ft_printf_flags.c \
		sources/ft_printf_utils.c

CC = gcc

INCLUDES = -I./includes

CFLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

SUPR_O = ft_printf.o \
		ft_printf_arg.o \
		ft_printf_width.o \
		ft_printf_preci.o \
		ft_printf_str.o \
		ft_printf_char.o \
		ft_printf_pointer.o \
		ft_printf_int.o \
		ft_printf_uint.o \
		ft_printf_percent.o \
		ft_printf_hexa.o \
		ft_printf_flags.o \
		ft_printf_utils.o

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)
	rm -f $(SUPR_O)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re