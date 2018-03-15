# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:20:07 by emarin            #+#    #+#              #
#    Updated: 2018/03/15 16:40:42 by emarin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh
NAME=disassembler
SRCS_PATH=src
OBJ_PATH=obj
INCLUDE_PATH=includes
LIB=libft.a
LIB_PATH=libft
LIB_INCLUDE_PATH=libft/includes

OBJ_NAME= disassembler.o \
			disassembler_util.o \
			op_utils.o \
			store_prog.o

OBJ=$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADERS=$(INCLUDE_PATH)/disassembler.h $(INCLUDE_PATH)/op.h \

FLAGS= -Wall -Wextra -Werror -I $(LIB_INCLUDE_PATH) -I $(INCLUDE_PATH) -g
LINK_FLAGS= -L $(LIB_PATH) -lft -lncurses -g


RED=\033[31m
GREEN=\033[32m
ORANGE=\033[33m
EOC=\033[0m

all: $(LIB) $(NAME)

$(NAME): $(LIB_PATH)/$(LIB) $(OBJ)
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
	@rm -f $(OBJ)
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r*.o"

fclean: clean
	@rm -f $(NAME)
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r$(NAME)"

re: fclean all
