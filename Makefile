NAME		=	pipex
BONUS		=	pipex_bonus

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

LIB			=	lib.a

LIB_DIR		=	./lib

INCLUDES	=	-I ./includes -I $(LIB_DIR)/includes

UTILS_DIR	=	$(SRCS_DIR)/utils
UTILS_SRCS	=	$(UTILS_DIR)/command.c \
				$(UTILS_DIR)/dup.c \
				$(UTILS_DIR)/fork.c \
				$(UTILS_DIR)/utils.c

SRCS_DIR	=	./srcs
SRCS		=	$(SRCS_DIR)/main.c $(UTILS_SRCS)
OBJS		=	$(SRCS:.c=.o)


BONUS_DIR	=	$(SRCS_DIR)/bonus
BONUS_SRCS	=	$(BONUS_DIR)/main.c $(UTILS_SRCS)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

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

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB_DIR)/$(LIB) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(BONUS) $(OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIB_DIR)/$(LIB) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus