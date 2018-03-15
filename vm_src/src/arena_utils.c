/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:06:19 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 01:26:30 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_arenacpy(unsigned char *dest, char *arena, int start, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = (i + start) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		dest[i] = arena[j];
		i++;
	}
}

void		arenacharge(t_vm *vm, unsigned char *src, long stsi, int player)
{
	int	i;
	int	j;
	int	start;
	int	size;

	start = (stsi >> 32) & 0xFFFFFFFF;
	size = stsi & 0xFFFFFFFF;
	i = 0;
	while (i < size)
	{
		j = (i + start) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		if (vm->visu == 1)
			vm->visual->arena_color[j] = player + 1;
		vm->arena[j] = src[i];
		i++;
	}
}

long long	arena_to_ll(char *arena, int start)
{
	char		reg[REG_SIZE];
	int			i;
	int			j;
	long long	ret;

	i = 0;
	while (i < REG_SIZE)
	{
		j = (i + start) % MEM_SIZE;
		if (j < 0)
			j += MEM_SIZE;
		reg[i] = arena[j];
		i++;
	}
	ret = ((reg[0] << 24) & 0xFF000000) | ((reg[1] << 16) & 0xFF0000)
		| ((reg[2] << 8) & 0xFF00) | (reg[3] & 0xFF);
	return (ret);
}
