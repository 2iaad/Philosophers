NAME = philo

CC = cc

FLAGS = -fsanitize=address

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
	$(CC) $(FLAGS) -g -pthread $^ -o $@

%.o : %.c philosophers.h
	$(CC) $(FLAGS) -g -pthread -c $< -o $@

clean :
	$(RM) $(SRC_OBJ)

fclean : clean
	$(RM) $(NAME)