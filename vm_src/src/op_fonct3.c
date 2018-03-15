/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fonct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:12:49 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/08 21:04:57 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	op_fork(t_process *process, t_vm *vm)
{
	short	dir;

	dir = (((unsigned char)process->instr[1] << 8) & 0xFF00)
		| ((unsigned char)process->instr[2] & 0xFF);
	fork_process(&(vm->process), process->pc + (dir % IDX_MOD), process, vm);
	return (1);
}

int	op_lld(t_process *process, t_vm *vm)
{
	unsigned char	*reg;
	long long		nb;
	long long		val;

	if (((process->instr[1] >> 6) & 3) == DIR_CODE)
	{
		reg = &(process->regs[(par_to_ll(process->instr + 2 + DIR_SIZE, 1) - 1)
		* REG_SIZE]);
		val = par_to_ll(process->instr + 2, DIR_SIZE);
		reg_charge(reg, val);
	}
	else
	{
		reg = &(process->regs[(par_to_ll(process->instr + 2 + IND_SIZE, 1) - 1)
		* REG_SIZE]);
		nb = par_to_ll(process->instr + 2, IND_SIZE);
		val = par_to_ll(&(vm->arena[(process->pc + nb) % MEM_SIZE]), REG_SIZE);
		reg_charge(reg, val);
	}
	process->carry = !val;
	return (1);
}

int	op_lldi(t_process *process, t_vm *vm)
{
	int			i;
	int			j;
	long long	addr;

	i = 2;
	addr = get_param(0, process, vm->arena, &i);
	addr += get_param(1, process, vm->arena, &i);
	ft_arenacpy(&process->regs[(process->instr[i] - 1) * REG_SIZE], vm->arena,
			process->pc + addr, REG_SIZE);
	process->carry = 1;
	j = 0;
	while (j < REG_SIZE)
	{
		if (process->regs[((process->instr[i] - 1) * REG_SIZE) + j] != 0)
		{
			process->carry = 0;
			break ;
		}
		j++;
	}
	return (1);
}

int	op_lfork(t_process *process, t_vm *vm)
{
	short	dir;

	dir = (((unsigned char)process->instr[1] << 8) & 0xFF00)
		| ((unsigned char)process->instr[2] & 0xFF);
	fork_process(&(vm->process), process->pc + dir, process, vm);
	return (1);
}

int	op_aff(t_process *process, t_vm *vm)
{
	if (vm->visu != 1)
		ft_putchar(process->regs[(process->instr[2]) * (REG_SIZE) - 1]);
	return (1);
}
