/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:41:50 by emarin            #+#    #+#             */
/*   Updated: 2018/03/07 19:10:38 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	init_vm(t_vm *vm)
{
	vm->process = NULL;
	vm->players = NULL;
	vm->visu = 0;
	if (!(vm->arena = ft_memalloc(MEM_SIZE)))
		return (ft_er("malloc error\n"));
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->dump_nbr_cycles = -1;
	vm->nblive_tot = 0;
	vm->time_last_reduction = 1;
	vm->cycle = 1;
	return (1);
}

int		player_nb_exist(t_vm *vm, char *player_nb, int nb)
{
	int	i;

	i = -1;
	while (++i < vm->nb_player)
		if (player_nb[i] && vm->players[i].num == nb)
			return (1);
	return (0);
}

void	set_player_nb(t_vm *vm, char *player_nb)
{
	int	i;
	int	nb;

	nb = 1;
	i = -1;
	while (++i < vm->nb_player)
	{
		vm->players[i].cycle_last_live = 0;
		if (!player_nb[i])
		{
			while (player_nb_exist(vm, player_nb, nb))
				++nb;
			vm->players[i].num = nb;
			player_nb[i] = 1;
		}
	}
}

void	print_arena(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2hhx", vm->arena[i]);
		if (i % 32 == 31)
			ft_putstr("\n");
		else
			ft_putchar(' ');
		i++;
	}
}
