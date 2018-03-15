# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 21:27:41 by lowczarc          #+#    #+#              #
#    Updated: 2018/03/15 15:59:33 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh
NAME=libft.a
SRCSPATH=srcs
INCLUDEPATH=includes

OBJ=ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	ft_strlen.o ft_strdup.o ft_memccpy.o ft_strcpy.o ft_strncpy.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o \
	ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o \
	ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o \
	ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
	ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o \
	ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
	ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o \
	ft_lstiter.o ft_lstmap.o ft_lstsort.o free_double_tab.o ft_strtablen.o \
	ft_rand.o ft_lstlen.o ft_lstgetn.o ft_sqrt.o ft_lstcreat.o ft_lstcpy.o \
	ft_atoi_l.o ft_strlen_unicode.o \
	printfutils.o flags_detect.o printf_char.o printf_int.o printf_pourcent.o \
	printf_string.o ft_wstr.o ft_lltoa.o ft_llxtoa.o ft_strfreejoin.o \
	ft_strlenc.o ft_putstrfinalc.o printf_float.o \
	get_next_line.o

HEADERS=$(INCLUDEPATH)/libft.h $(INCLUDEPATH)/ft_printf.h \
	   	$(INCLUDEPATH)/get_next_line.h

FLAGS= -Wall -Wextra -Werror -I $(INCLUDEPATH)

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

%.o: $(SRCSPATH)/%.c $(HEADERS)
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
