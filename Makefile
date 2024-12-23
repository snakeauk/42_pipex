NAME		=	pipex
BONUS		=	pipex_bonus

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

LIBFT		=	libft
LIBFT_A		=	$(LIBFT).a
LIBFT_DIR	=	./$(LIBFT)

SRCS_DIR	=	./srcs
UTILS_DIR	=	$(SRCS_DIR)/utils
UTILS_SRCS	=	$(UTILS_DIR)/child.c \
				$(UTILS_DIR)/env.c \
				$(UTILS_DIR)/file.c \
				$(UTILS_DIR)/ft_fork.c \
				$(UTILS_DIR)/ft_split_cmd.c \
				$(UTILS_DIR)/here_doc.c \
				$(UTILS_DIR)/pipex.c
UTILS_OBJS	=	$(UTILS_SRCS:.c=.o)

MAN_DIR		=	$(SRCS_DIR)/mandatory
MAN_SRCS	=	$(MAN_DIR)/main.c
MAN_OBJS	=	$(MAN_SRCS:.c=.o)

BONUS_DIR	=	$(SRCS_DIR)/bonus
BONUS_SRCS	=	$(BONUS_DIR)/main.c
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_DIR		=	$(LIBFT_DIR)/mac
else
	OS_DIR		=	$(LIBFT_DIR)/linux
endif

INCLUDES	=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_DIR)/includes

RESET		=	\033[0m
BOLD		=	\033[1m
DIM			=	\033[2m
UNDERLINE	=	\033[4m
BLINK		=	\033[5m
INVERT		=	\033[7m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

MAKEFLAGS	+=	--no-print-directory

all: $(NAME)

$(NAME): $(UTILS_OBJS) $(MAN_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@echo "$(BOLD)$(LIGHT_BLUE)Compile now...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAG) $(INCLUDES) $(UTILS_OBJS) $(MAN_OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(MAN_OBJS) $(BONUS_OBJS) $(UTILS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(MAN_OBJS) $(BONUS_OBJS) $(UTILS_OBJS) $(NAME) $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: $(BONUS)

$(BONUS): $(UTILS_OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAG) $(INCLUDES) $(UTILS_OBJS) $(BONUS_OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus