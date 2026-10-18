NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS    =	ft_printf.c \
			ft_print_hexa.c \
			ft_putnbr.c \
			ft_unsigned_putnbr.c \
			ft_putchar.c \
			ft_putstr.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re