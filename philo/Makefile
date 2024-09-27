# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 09:50:22 by zderfouf          #+#    #+#              #
#    Updated: 2024/09/27 22:19:04 by zderfouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = #-fsanitize=thread

RM = rm -rf

SRC =	main.c \
		utils.c \
		parsing.c \
		philo_init.c \
		philo_creation.c \
		philo_helper.c \
		philo_actions.c \

SRC_OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC_OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.c philosophers.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(SRC_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all 
