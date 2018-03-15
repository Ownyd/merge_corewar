# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:20:07 by emarin            #+#    #+#              #
#    Updated: 2018/03/15 15:51:18 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh
NAME=asm
SRCS_PATH=src
OBJ_PATH=obj
INCLUDE_PATH=inc
LIB=libft.a
LIB_PATH=libft

OBJ_NAME=	add_infos.o \
			commandlist.o \
			delspaces_tab.o \
			first_parse.o \
			ft_cmdadd.o \
			ft_cmddel.o \
			ft_cmdnew.o \
			ft_labeladd.o \
			ft_labeldel.o \
			ft_labelnew.o \
			ft_outputadd.o \
			ft_outputdel.o \
			ft_outputnew.o \
			line_errors.o \
			main.o \
			misc.o \
			opc.o \
			param_errors.o \
			store_label.o \
			store_output.o \
			utils.o \
			valid_line.o \
			validity_params.o 


OBJ=$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADERS=$(INCLUDE_PATH)/asm.h

FLAGS= -Wall -Wextra -Werror -I $(INCLUDE_PATH) 
LINK_FLAGS= -L $(LIB_PATH) -lft


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
