NAME		=	pipex

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

LIB			=	lib.a

LIB_DIR		=	./lib

INCLUDES	=	-I ./includes -I $(LIB_DIR)/includes

UTILS_DIR	=	$(SRCS_DIR)/utils

SRCS_DIR	=	./srcs
MAN_DIR		=	$(SRCS_DIR)/mandatory
SRCS		=	$(wildcard $(SRCS_DIR)/*.c $(MAN_DIR)/main.c)
OBJS		=	$(SRCS:.c=.o)

BONUS		=	pipex_bonus
BONUS_DIR	=	$(SRCS_DIR)/bonus
BONUS_SRCS	=	$(wildcard $(SRCS_DIR)/*.c $(BONUS_DIR)/main.c)
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
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB_DIR)/$(LIB) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME) $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: fclean $(BONUS_OBJS) $(OBJS)
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIB_DIR)/$(LIB) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus