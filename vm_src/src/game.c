/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:10:32 by emarin            #+#    #+#             */
/*   Updated: 2018/03/08 17:52:14 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reset_player_nb_lives(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->nb_player)
	{
		vm->players[i].nb_lives = 0;
		i++;
	}
}

void	check_nblive(t_vm *vm)
{
	t_process	*proc;
	t_process	*tmp;

	if (vm->nblive_tot >= NBR_LIVE || vm->time_last_reduction + 1 >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->time_last_reduction = 0;
	}
	else
		vm->time_last_reduction++;
	proc = vm->process;
	while (proc)
	{
		tmp = proc;
		proc = proc->next;
		if (!tmp->nblive)
			remove_process(&(vm->process), tmp);
		else
			tmp->nblive = 0;
	}
	reset_player_nb_lives(vm);
	vm->nblive_tot = 0;
}

char	make_one_cycle(t_vm *vm)
{
	t_process	*process;

	process = vm->process;
	while (process)
	{
		if (!charge_name_instr(process, vm))
			return (0);
		if (!process_execution(process, vm))
			return (0);
		process = process->next;
	}
	return (1);
}

char	loop_vm(t_vm *vm)
{
	int		current_cycle;

	current_cycle = vm->cycle_to_die;
	while (vm->process)
	{
		if (!(make_one_cycle(vm)))
			return (0);
		if (--(current_cycle) <= 0
				|| vm->cycle_to_die <= 0)
		{
			check_nblive(vm);
			current_cycle = vm->cycle_to_die;
		}
		if (vm->visu == 1)
			visu_ncurses(vm);
		if (vm->cycle == vm->dump_nbr_cycles)
		{
			print_arena(vm);
			exit(close_vm(vm, 0));
		}
		vm->cycle++;
	}
	return (1);
}
