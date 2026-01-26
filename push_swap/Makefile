NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Lista di tutti i tuoi file .c
SRCS = push_swap.c \
       utilities.c \
       utilities2.c \
       utilities3.c \
       ft_split.c \
       push.c \
       rotate.c \
       swap.c \
       sorting.c \
       reverse_rotate.c

# Crea la lista degli oggetti (.o)
OBJS = $(SRCS:.c=.o)

# Regola principale
all: $(NAME)

# Linker
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilatore
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
