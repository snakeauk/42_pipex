NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS_DIR = ./srcs

SRCS =	$(SRCS_DIR)/get_next_line.c

OBJS = $(SRCS:.c=.o)

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re