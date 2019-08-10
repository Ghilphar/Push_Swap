# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 09:32:48 by fgaribot          #+#    #+#              #
#    Updated: 2019/08/10 10:45:31 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = checker
#NAME2 = Push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra # -I ./includes
LIBFT_DIR = ./srcs/libft/
SRC = ./srcs/
FILES = $(SRC)pushs.c\
		$(SRC)swaps.c\
		$(SRC)rotate.c\
		$(SRC)reverse_rotate.c\
		$(SRC)checker_tests.c\
		$(SRC)checker_exits.c\
		$(SRC)checker.c

OBJ= $(FILES:.c=.o)

all : libft $(EXEC) # $(NAME2)

libft :
	@(cd $(LIBFT_DIR) && $(MAKE)) 

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ ./srcs/libft/libft.a

clean :
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	rm -f $(OBJ)

fclean: clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	rm -f $(EXEC)

re: fclean all