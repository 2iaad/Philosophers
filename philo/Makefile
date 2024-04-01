NAME = philo

CC = cc

FLAGS = 

RM = rm -rf

SRC =	main.c \
		utils.c \
		parsing.c \

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