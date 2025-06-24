NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test_gnl

re: fclean all

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o test_gnl
	./test_gnl

.PHONY: all clean fclean re test
