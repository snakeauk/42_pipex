NAME		=	pipex
BONUS		=	checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

LIB			=	lib.a

LIB_DIR		=	./lib

SRCS_DIR	=	./srcs
UTILS_DIR	=	$(SRCS_DIR)/utils
INCLUDES	=	-I ./includes -I $(LIB_DIR)/includes
SRCS		=	$(wildcard $(SRCS_DIR)/*.c $(UTILS_DIR)/*.c)
OBJS		=	$(SRCS:.c=.o)

# BONUS_DIR	=	./bonus
# BONUS_SRCS	=	$(filter-out $(BONUS_DIR)/main.c, $(wildcard $(BONUS_DIR)/*.c))
# BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

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

$(NAME): $(OBJS) $(LIB_OBJS) $(SRCS_DIR)/main.o
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB_DIR)/$(LIB) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"\

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(OBJS) $(LIB_OBJS) $(BONUS_DIR)/main.o
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS) $(LIB_OBJS) $(BONUS_DIR)/main.o -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(LIB_OBJS) $(SRCS_DIR)/main.o $(BONUS_DIR)/main.o
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME) $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

re: fclean all bonus

.PHONY: all clean fclean re