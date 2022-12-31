# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 15:51:25 by sungohki          #+#    #+#              #
#    Updated: 2022/12/31 18:27:51 by sungohki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar
AROPTS = rcus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c\
	./libft/ft_isprint.c ./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c\
	./libft/ft_memmove.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c ./libft/ft_toupper.c ./libft/ft_tolower.c\
	./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c ./libft/ft_memchr.c ./libft/ft_memcmp.c\
	./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_strdup.c\
	./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c\
	./libft/ft_strmapi.c ./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c\
	./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putnbr_hex_fd.c ./libft/ft_putnbr_us_fd.c\
	./libft/ft_putaddr_fd.c ./libft/ft_subaddr.c ./libft/ft_itoa_us.c ./libft/ft_itoa_hex.c\
	./libft/ft_lstnew.c ./libft/ft_lstadd_front.c ./libft/ft_lstsize.c ./libft/ft_lstlast.c\
	./libft/ft_lstadd_back.c ./libft/ft_lstdelone.c ./libft/ft_lstclear.c ./libft/ft_lstiter.c\
	./libft/ft_lstmap.c\
	./ft_detect_fm.c ./ft_devide_fm.c ./ft_printf.c ./ft_str_fm.c ./ft_write_fm.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = ./ft_printf.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : all

all:
	$(AR) $(AROPTS) $(NAME) $^
	touch $@

all : $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -f $(NAME) all

re : fclean all

.PHONY : clean fclean re
