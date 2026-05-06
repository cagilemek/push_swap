NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		parse_arg.c \
		parse_flag.c \
		split.c \
		utils_1.c \
		utils_2.c \
		disorder.c \
		algo_simple.c \
		algo_medium.c \
		algo_complex.c \
		two_three_five.c \
		operations_push.c \
		operations_rotate.c \
		operations_swap.c \
		operations_reverse_rotate.c \
		u_bench_flag.c \
		u_bench_write.c \
		u_find_pos.c \
		u_init_counts.c \
		utils_0.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re