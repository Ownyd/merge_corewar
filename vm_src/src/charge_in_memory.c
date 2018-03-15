/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_in_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:41:45 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 01:30:51 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	charge_player_in_memory(t_player *player, int start, int j,
		t_vm *vm)
{
	int	i;

	i = 0;
	while (i < player[j].prog_size)
	{
		if (vm->visu == 1)
			vm->visual->arena_color[(start + i) % MEM_SIZE] = j + 1;
		vm->arena[(start + i) % MEM_SIZE] = player[j].prog[i];
		i++;
	}
}

void	charge_memory(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->nb_player)
	{
		charge_player_in_memory(vm->players,
				(MEM_SIZE / vm->nb_player) * i, i, vm);
		add_process(&(vm->process), (MEM_SIZE / vm->nb_player) * i,
			vm->players[i].num, i);
		free(vm->players[i].prog);
		i++;
	}
}
