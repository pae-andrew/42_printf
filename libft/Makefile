# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pae-andrew <pae-andrew@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 13:15:18 by qadmiral          #+#    #+#              #
#    Updated: 2020/11/30 20:28:11 by pae-andrew       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC= ft_putchar.c ft_strmapi.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_split.c ft_itoa.c ft_strtrim.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS= ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c 

OBJ=$(SRC:.c=.o)

OBJ_BONUS=$(BONUS:.c=.o)

$(NAME): $(OBJ) libft.h
	$(CC) $(CFLAGS) -c $(SRC) -I /
	ar rc $(NAME) $(OBJ) 

all: $(NAME)

bonus: $(OBJ) $(OBJ_BONUS) libft.h
	$(CC) $(CFLAGS) -c $(SRC) $(BONUS) -I /
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus
