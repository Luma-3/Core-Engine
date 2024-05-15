# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 21:44:08 by jbrousse          #+#    #+#              #
#    Updated: 2024/05/15 11:40:36 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## 	COMPILE	 ##
###############

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g3

################
##   LIBS	  ##
################

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= libs/libft/
LIBFT_INC	= $(LIBFT_DIR)includes/

MLX			= $(MLX_DIR)libmlx.a
MLX_DIR		= libs/minilibx/
MLX_INC		= $(MLX_DIR)

VECTORFT	= $(VECTORFT_DIR)vectorft.a
VECTORFT_DIR= libs/vectorft/
VECTORFT_INC= $(VECTORFT_DIR)includes/

##############
##  SOURCE	##
##############

SRC_DIR				=	sources/

SRC_CLOSING_DIR		=	stop_components/
SRC_CLOSING_LIST	=	stop_engine.c
SRC_CLOSING			=	$(addprefix $(SRC_CLOSING_DIR), $(SRC_CLOSING_LIST))

SRC_INIT_DIR		=	initializer/
SRC_INIT_LIST		=	init_engine.c	\
						init_render.c	\
						init_window.c
SRC_INIT			=	$(addprefix $(SRC_INIT_DIR), $(SRC_INIT_LIST))

SRC_IO_DIR			=	io/
SRC_IO_LIST			=	event.c			\
						keys_press.c
SRC_IO				=	$(addprefix $(SRC_IO_DIR), $(SRC_IO_LIST))

SRC_LOGGING			=	logger/
SRC_LOG_LIST		=	logging.c		\
						logging_msg.c
SRC_LOG				=	$(addprefix $(SRC_LOGGING), $(SRC_LOG_LIST))

SRC_OBJ_DIR			=	object/
SRC_OBJ_LIST		=	object.c \
						debug.c	
SRC_OBJ				=	$(addprefix $(SRC_OBJ_DIR), $(SRC_OBJ_LIST))

SRC_RENDERER_DIR	=	renderer/

SRC_2D_DIR			=	2d_component/
SRC_2D_LIST			=	init_render2d.c	\
						basic_draw.c	\
						debug_draw.c
SRC_2D				=	$(addprefix $(SRC_2D_DIR), $(SRC_2D_LIST))

SRC_RENDERER_LIST	=	$(SRC_2D)		\
						draw_utils.c	\
						frame.c			\
						renderer.c
SRC_RENDERER		=	$(addprefix $(SRC_RENDERER_DIR), $(SRC_RENDERER_LIST))

SRC_LIST			=	get_engine.c	\
						loop.c			\
						coordinate.c	\
						$(SRC_LOG)		\
						$(SRC_OBJ)		\
						$(SRC_INIT)		\
						$(SRC_IO)		\
						$(SRC_CLOSING)	\
						$(SRC_RENDERER)	
SRC					=	$(addprefix $(SRC_DIR), $(SRC_LIST))

################
##	INCLUDES  ##
################

INC_LST		=	./includes/		\
				./$(MLX_INC)	\
				./$(LIBFT_INC)	\
				./$(VECTORFT_INC)
INCLUDES	=	$(addprefix -I, $(INC_LST))			

################
##	OBJ/NAME  ##
################

NAME		=	core_engine.a

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

#################
##	 COLORS	   ##
#################

COLOR_RESET		=	\033[0m
COLOR_GREEN		=	\033[38;5;76m
COLOR_RED		=	\033[38;5;160m
COLOR_BLUE		=	\033[38;5;45m
COLOR_ORANGE	=	\033[38;5;220m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m

################
##	PROGRESS  ##
################

COMPILED_SRCS		:=	1

TOTAL_SRCS			:=	$(words $(SRC))


MAX_PATH_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' | awk '{print length}' | sort -nr | head -n1)
MAX_NAME_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' -exec basename {} \; | awk '{ print length }' | sort -nr | head -n1)

define progress_bar
	printf "$(COLOR_BLUE)Compiling: [$(COLOR_GREEN)"; \
	for i in $$(seq 1 $(4)); do \
		if [ $$i -le $$(($(1)*$(4)/$(2))) ]; then \
			printf "#"; \
		else \
			printf "."; \
		fi; \
	done; \
	printf "$(COLOR_BLUE)] $(BOLD)$(1)/$(2) $(COLOR_GREEN)$(3)$(COLOR_RESET)\r"
endef

define print_progress
	@$(eval WIDTH := $(shell tput cols))
	@$(eval LEN := $(shell expr $(WIDTH) - $(MAX_PATH_LENGTH) - 26))
	
	@printf "\033[2K"; \
	if [ $(LEN) -le 10 ]; then \
		printf "$(COLOR_BLUE)Compiling: $(BOLD)$(1)/$(2)$(COLOR_RESET)$(COLOR_GREEN) $(notdir $(3))$(COLOR_RESET)\r"; \
	else \
		$(call progress_bar,$(1),$(2),$(3),$(LEN)); \
	fi
endef

#############
##	RULES  ##
#############

all: $(NAME)  

$(MLX):
	@make -sC $(MLX_DIR)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(VECTORFT):
	@make -sC $(VECTORFT_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(VECTORFT)
	@ar -x $(LIBFT) --output=$(OBJ_DIR)
	@ar -x $(MLX) --output=$(OBJ_DIR)
	@ar -x $(VECTORFT) --output=$(OBJ_DIR)
	@ar -rc $(NAME) $(OBJ) $(OBJ_DIR)*.o
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)$(BOLD)$(NAME) is Ready !$(COLOR_RESET)"

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME) objects$(COLOR_RESET)"
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(VECTORFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME)$(COLOR_RESET)"
	@rm -f $(LIBFT)
	@echo "$(COLOR_RED)$(BOLD)Delete $(LIBFT)$(COLOR_RESET)"
	@rm -f $(MLX)
	@echo "$(COLOR_RED)$(BOLD)Delete $(MLX)$(COLOR_RESET)"
	@rm -f $(VECTORFT)
	@echo "$(COLOR_RED)$(BOLD)Delete $(VECTORFT)$(COLOR_RESET)"

re: fclean all

norme:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -v Norme -B 1 || true

.PHONY: all clean fclean re