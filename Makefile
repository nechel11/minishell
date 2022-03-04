# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbyrd <nbyrd>                              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:34:08 by bepifani          #+#    #+#              #
#    Updated: 2022/02/21 16:26:08 by nbyrd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h
LIBFT = bible2/libft.a

FLAGS = gcc -Wall -Wextra -Werror
RFLAG = -lreadline

FILES =	main.c 1pwd.c 1echo.c 1env.c \
		errors.c init.c \

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o: %.c $(HEADER)
	$(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT) $(HEADER)
	$(FLAGS)  $(OBJ) $(LIBFT) $(RFLAG) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re