# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 18:17:48 by lowczarc          #+#    #+#              #
#    Updated: 2018/03/15 18:24:11 by lowczarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh

all: corewar asm disassembler

corewar:
	@make -C vm_src

asm:
	@make -C asm_src

disassembler:
	@make -C dis_src

.PHONY: corewar asm disassembler clean fclean re

clean:
	@make -C vm_src clean
	@make -C asm_src clean
	@make -C dis_src clean

fclean:
	@make -C vm_src fclean
	@make -C asm_src fclean
	@make -C dis_src fclean

re:
	@make -C vm_src re
	@make -C asm_src re
	@make -C dis_src re
