/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_operands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:50:43 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/07 17:33:21 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reg_and(char *reg1, char *reg2, char *reg3)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg3[i] = reg1[i] & reg2[i];
		i++;
	}
}

void	reg_or(char *reg1, char *reg2, char *reg3)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg3[i] = reg1[i] | reg2[i];
		i++;
	}
}

void	reg_xor(char *reg1, char *reg2, char *reg3)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg3[i] = reg1[i] ^ reg2[i];
		i++;
	}
}

void	reg_add(char *reg1, char *reg2, char *reg3)
{
	int				i;
	unsigned short	tmp;

	i = 0;
	tmp = 0;
	while (i < REG_SIZE)
	{
		tmp = ((unsigned short)reg1[REG_SIZE - i - 1] & 0xFF)
			+ ((unsigned short)reg2[REG_SIZE - i - 1] & 0xFF) + (tmp > 0xFF);
		reg3[REG_SIZE - i - 1] = tmp & 0xFF;
		i++;
	}
}

void	reg_sub(char *reg1, char *reg2, char *reg3)
{
	int				i;
	unsigned short	tmp;

	i = 0;
	tmp = 0;
	while (i < REG_SIZE)
	{
		tmp = ((unsigned short)reg1[REG_SIZE - i - 1] & 0xFF)
			- ((unsigned short)reg2[REG_SIZE - i - 1] & 0xFF) - (tmp > 0xFF);
		reg3[REG_SIZE - i - 1] = tmp & 0xFF;
		i++;
	}
}
