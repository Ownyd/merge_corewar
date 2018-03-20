# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:20:07 by emarin            #+#    #+#              #
#    Updated: 2018/03/20 11:59:59 by lowczarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh
NAME=../corewar
SRCS_PATH=src
OBJ_PATH=obj
INCLUDE_PATH=includes
LIB=libft.a
LIB_PATH=libft
LIB_INCLUDE_PATH=libft/includes

OBJ_NAME=	corewar.o \
			vm_util.o \
			util.o \
			store_prog.o \
			charge_in_memory.o \
			process.o \
			reg_utils.o \
			game.o \
			process_execution.o \
			op_fonct1.o \
			op_fonct2.o \
			op_fonct3.o \
			op_fonct4.o \
			op_utils.o \
			reg_operands.o \
			arena_utils.o \
			print_winner.o \
			visu_ncurses.o \
			visu_ncurses_print.o \
			visu_ncurses_util.o

OBJ=$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADERS=$(INCLUDE_PATH)/corewar.h $(INCLUDE_PATH)/op.h \
		$(INCLUDE_PATH)/visu_ncurses.h

FLAGS= -Wall -Wextra -Werror -I $(LIB_INCLUDE_PATH) -I $(INCLUDE_PATH)
LINK_FLAGS= -L $(LIB_PATH) -lft -lncurses


RED=\033[31m
GREEN=\033[32m
ORANGE=\033[33m
EOC=\033[0m

all: $(LIB) $(NAME)

.display:
	@echo "--> make $(ORANGE)$(NAME)$(EOC)"
	@touch .display

$(NAME): $(LIB_PATH)/$(LIB) .display $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LINK_FLAGS)
	@echo "\n\t                  $(GREEN)[SUCCESS]$(EOC)\c"
	@echo "\r$(NAME)"

$(OBJ_PATH)/%.o:$(SRCS_PATH)/%.c $(HEADERS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc -o $@ -c $< $(FLAGS)
	@echo "\r\t                  $(GREEN)[SUCCESS]$(EOC)\c"
	@echo "\r$@\c"

$(LIB):
	@$(MAKE) -C $(LIB_PATH)

.PHONY: fclean all clean re $(LIB)

clean:
	@echo "--> fclean $(ORANGE)$(LIB_PATH)/$(EOC)"
	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -rf $(OBJ_PATH)
	@rm -f .display
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r*.o"

fclean: clean
	@rm -f $(NAME)
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r$(NAME)"

re: fclean all
