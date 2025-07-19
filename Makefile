NAME = libft.a
NAME_TEST = test

CC = gcc
FLAGS = -Wall -Wextra -Werror

C_SRC = $(filter-out minunit_example.c, $(wildcard *.c))
OBJ = $(C_SRC:.c=.o)
H_SRC = $(wildcard *.h)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

$(NAME_TEST) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_TEST)

re: fclean all

re$(NAME_TEST): fclean $(NAME_TEST)
