# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 21:27:41 by lowczarc          #+#    #+#              #
#    Updated: 2018/03/20 11:53:06 by lowczarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh
NAME=libft.a
SRCSPATH=srcs

OBJ= ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	 ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o \
	 ft_lstdelone.o ft_contdel.o ft_lstiter.o ft_lstmap.o ft_lstnew.o \
	 ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
	 ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o \
	 ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
	 ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
	 ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o \
	 ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o \
	 ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o \
	 ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
	 ft_strsplit.o ft_strtrim.o ft_strsub.o ft_toupper.o ft_tolower.o \
	 ft_strstr.o ft_strnstr.o ft_strrchr.o ft_count_if.o ft_foreach.o \
	 ft_print_params.o ft_sqrt.o ft_swap.o get_next_line.o \
	 ft_atoll.o ft_strfreejoin.o ft_strfreesub.o \
	 ft_isstrdigit.o ft_atoll.o \
	 ft_tabfree.o ft_isstrblank.o \
	 ft_delspaces.o ft_putstrlen.o ft_pow.o ft_strocur.o\

HEADERS=libft.h get_next_line.h 

FLAGS= -Wall -Wextra -Werror -I .

RED=\033[31m
GREEN=\033[32m
ORANGE=\033[33m
EOC=\033[0m

all: $(NAME)

.display:
	@echo "--> make   $(ORANGE)libft/$(EOC)"
	@touch .display

$(NAME):.display $(OBJ)
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)
	@echo "\n\t                  $(GREEN)[SUCCESS]$(EOC)\c"
	@echo "\r\t$(NAME)"

%.o:%.c $(HEADERS)
	@gcc -o $@ -c $< $(FLAGS)
	@echo "\r\t                  $(GREEN)[SUCCESS]$(EOC)\c"
	@echo "\r\t$@\c"

.PHONY: fclean all clean re

clean:
	@rm -f $(OBJ)
	@rm -f .display
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r\t*.o"

fclean: clean
	@rm -f $(NAME)
	@echo "\t                  $(RED)[DELETED]$(EOC)\c"
	@echo "\r\t$(NAME)"

re: fclean all
