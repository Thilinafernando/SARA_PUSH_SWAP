NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I/usr/include -Ilibft

LIBFTDIR =libft/
LIBFT = $(LIBFTDIR)libft.a

SRC = push_swap.c \
		algo.c \
		utils.c \
		errors.c \
		op_two.c \
		op_one.c \
		ft_list.c \
		op_three.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -o $(NAME) $(INCLUDES)
%.o: %.c
		$(CC) -c $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
