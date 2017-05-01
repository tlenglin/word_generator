# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 13:07:33 by tlenglin          #+#    #+#              #
#    Updated: 2017/05/01 14:50:30 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= wd_gen
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
LIBFT   		= -L ./libft -lft
SRC				= main.c install.c
OBJ				= $(SRC:.c=.o)

########################
#    Makefile rules    #
########################
all: $(NAME)

# Executable
$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT)

# Cleaning rules
clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Cleaning [$(OBJ) libft]"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "Cleaning [wd_gen]"

re: fclean all

.PHONY: clean fclean re
