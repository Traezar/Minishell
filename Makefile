# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 08:38:15 by rsathiad          #+#    #+#              #
#    Updated: 2018/11/09 23:35:06 by rsathiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = minishell

SRC = $(mini)

OBJ = builtin.o env.o mini_main.o mini_cd.o mini_echo.o \
			mini_env.o mini_exit.o mini_setenv.o mini_unsetenv.o

HDR = mini.h

mini =	builtin.c env.c mini_main.c mini_cd.c mini_echo.c mini_env.c \
			mini_exit.c mini_setenv.c mini_unsetenv.c

LIB =  -lft -L ./libft/
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB)

$(LIBFT):
					cd libft/ && make
					@ echo "Library created in libft"

cmp:
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB)


clean:
	rm -rf $(OBJ)
	@ echo "Objects have been removed"

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	cd libft/ && rm -rf *.o

	@ echo "Executable has been removed."
	@ echo "Library deleted."

re: fclean all

CFLAGS = -Wall -Werror -Wextra

PHONY:
	clean fclean all re
