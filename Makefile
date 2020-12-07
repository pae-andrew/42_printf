# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 13:15:18 by qadmiral          #+#    #+#              #
#    Updated: 2020/12/01 20:37:27 by gcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

FLAGS = gcc -Wall -Wextra -Werror $(LIBFT_H) -c -o

LIBFT_H = -I libft/
PRINTF_H = -I srcs/

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = libft/

CFILES = ft_printf.c \
		check.c \
		ft_itoa_unsigned.c \
		set_parse.c \
		print_res.c \
		print_res2.c \
		ft_putstr.c \
		get_put.c \

CFIND = $(CFILES:%=$(SRC_DIR)%)

OFILES = $(CFILES:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILES))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
				@make -C $(LIB_DIR)
				@echo Copy $(LIB_DIR)$(LIBFT) to root
				@cp $(LIB_DIR)$(LIBFT) .
				@mv $(LIBFT) $(NAME)
				@echo $(NAME) $(OBJ)
				ar -src $(NAME) $(addprefix $(OBJ_DIR), $(OFILES))
$(OBJ): $(CFIND)
				@$(MAKE) $(OFILES)
$(OFILES):
			@echo Compiled: $(@:obj/%=%)
			@$(FLAGS) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
clean:
				@make clean -C $(LIB_DIR)
				/bin/rm -rf $(OBJ_DIR)

fclean:			clean
				@make fclean -C $(LIB_DIR)
				/bin/rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re
