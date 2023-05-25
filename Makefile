# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 19:20:08 by jlaisney          #+#    #+#              #
#    Updated: 2023/05/25 23:20:26 by jlaisney         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc -g
FLAGS = -Wall -Wextra #-Werror 
SRC =	main.c \
		ops_rot.c \
		ops.c \
		list_init.c \
		create_array.c \
		itoa_atoi.c \
		checkargs.c \
		utils.c \
		utils2.c \
		chuncks.c \
		sort_x.c \
		debugprints.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@
	rm -rf *.o
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all


		