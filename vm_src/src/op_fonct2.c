/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fonct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:11:24 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 01:28:48 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	op_or(t_process *process, t_vm *vm)
{
	unsigned char	*reg;
	long long		val[2];

	reg = and_or_xor_loop(process, vm, val);
	reg_charge(reg, val[0] | val[1]);
	process->carry = !par_to_ll((char *)reg, REG_SIZE);
	return (1);
}

int	op_xor(t_process *process, t_vm *vm)
{
	unsigned char	*reg;
	long long		val[2];

	reg = and_or_xor_loop(process, vm, val);
	reg_charge(reg, val[0] ^ val[1]);
	process->carry = !par_to_ll((char *)reg, REG_SIZE);
	return (1);
}

int	op_zjmp(t_process *process, t_vm *vm)
{
	short		dir;
	long long	new;

	dir = (((unsigned char)process->instr[1] << 8) & 0xFF00)
		| ((unsigned char)process->instr[2] & 0xFF);
	new = (process->pc + (((dir % IDX_MOD) - 1) % MEM_SIZE));
	if (new < 0)
		new += MEM_SIZE;
	if (process->carry)
	{
		process->pc = new;
		return (0);
	}
	return (1);
	(void)vm;
}

int	op_ldi(t_process *process, t_vm *vm)
{
	int			i;
	long long	addr;

	i = 2;
	addr = get_param(0, process, vm->arena, &i);
	addr += get_param(1, process, vm->arena, &i);
	ft_arenacpy(&process->regs[(process->instr[i] - 1) * REG_SIZE], vm->arena,
			process->pc + (addr % IDX_MOD), REG_SIZE);
	return (1);
}

int	op_sti(t_process *process, t_vm *vm)
{
	int			i;
	long long	addr;

	i = 3;
	addr = get_param(1, process, vm->arena, &i);
	addr += get_param(2, process, vm->arena, &i);
	arenacharge(vm, &process->regs[(process->instr[2] - 1) * REG_SIZE],
			((process->pc + (addr % IDX_MOD)) << 32) | REG_SIZE,
			process->player);
	return (1);
}
