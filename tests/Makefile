# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 22:19:29 by jbrousse          #+#    #+#              #
#    Updated: 2024/04/28 12:15:58 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INC = -I ../inc -I ../libs/minilibx -I ../libs/libft/includes

# If `init_core` is in a library, add the library to your linker flags
LDFLAGS = ../core_engine.a ../libs/minilibx/libmlx.a ../libs/libft/libft.a -lXext -lX11 -lm

# Then your rule to build the executable might look something like this
test:
	@make -C ../
	@$(CC) $(INC) main.c $(LDFLAGS) -o test.out 
	@echo "Compilation done"

re_p: 
	@rm -f test.out
	@make -sC ../
	@make -s test

rere: 
	@rm -f test.out
	@make -sC ../ re
	@make -s test

PHONY: test re_p rere