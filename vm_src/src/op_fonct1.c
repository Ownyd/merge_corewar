/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fonct1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:50:16 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/08 17:45:38 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	op_live(t_process *process, t_vm *vm)
{
	int i;
	int num;

	num = par_to_ll(process->instr + 1, DIR_SIZE);
	i = 0;
	while (i < vm->nb_player && vm->players[i].num != num)
		++i;
	if (i < vm->nb_player)
	{
		vm->players[i].cycle_last_live = vm->cycle;
		vm->players[i].nb_lives++;
		if (vm->visu != 1)
			ft_printf("un processus dit que le joueur %s est en vie\n"
				, vm->players[i].name);
		process->player = i;
	}
	++(process->nblive);
	vm->nblive_tot++;
	return (1);
}

int	op_ld(t_process *process, t_vm *vm)
{
	unsigned char	*reg;
	long long		nb;
	long long		val;

	if (((process->instr[1] >> 6) & 3) == DIR_CODE)
	{
		reg = &(process->regs[(par_to_ll(process->instr + 2 + DIR_SIZE, 1) - 1)
		* REG_SIZE]);
		val = par_to_ll(process->instr + 2, DIR_SIZE);
	}
	else
	{
		reg = &(process->regs[(par_to_ll(process->instr + 2 + IND_SIZE, 1) - 1)
		* REG_SIZE]);
		nb = par_to_ll(process->instr + 2, IND_SIZE);
		val = par_to_ll(&(vm->arena[(process->pc + (nb % IDX_MOD) % MEM_SIZE)]),
				REG_SIZE);
	}
	reg_charge(reg, val);
	process->carry = !val;
	(void)vm;
	return (1);
}

int	op_add(t_process *process, t_vm *vm)
{
	unsigned char	*reg1;
	unsigned char	*reg2;
	unsigned char	*reg3;
	long long		res;

	reg1 = &(process->regs[(par_to_ll(process->instr + 2, 1) - 1) * REG_SIZE]);
	reg2 = &(process->regs[(par_to_ll(process->instr + 3, 1) - 1) * REG_SIZE]);
	reg3 = &(process->regs[(par_to_ll(process->instr + 4, 1) - 1) * REG_SIZE]);
	reg_add((char *)reg1, (char *)reg2, (char *)reg3);
	res = par_to_ll((char *)reg3, REG_SIZE);
	process->carry = !res;
	(void)vm;
	return (1);
}

int	op_sub(t_process *process, t_vm *vm)
{
	unsigned char	*reg1;
	unsigned char	*reg2;
	unsigned char	*reg3;
	long long		res;

	reg1 = &(process->regs[(par_to_ll(process->instr + 2, 1) - 1) * REG_SIZE]);
	reg2 = &(process->regs[(par_to_ll(process->instr + 3, 1) - 1) * REG_SIZE]);
	reg3 = &(process->regs[(par_to_ll(process->instr + 4, 1) - 1) * REG_SIZE]);
	reg_sub((char *)reg1, (char *)reg2, (char *)reg3);
	res = par_to_ll((char *)reg3, REG_SIZE);
	process->carry = !res;
	(void)vm;
	return (1);
}

int	op_and(t_process *process, t_vm *vm)
{
	unsigned char	*reg;
	long long		val[2];

	reg = and_or_xor_loop(process, vm, val);
	reg_charge(reg, val[0] & val[1]);
	process->carry = !par_to_ll((char *)reg, REG_SIZE);
	return (1);
}
