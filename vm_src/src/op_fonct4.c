/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fonct4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:14:44 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 01:29:01 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				op_st(t_process *process, t_vm *vm)
{
	short	ind;

	if (((process->instr[1] >> 4) & 3) == REG_CODE)
	{
		reg_clone(&process->regs[REG_SIZE * (process->instr[3] - 1)],
				&process->regs[REG_SIZE * (process->instr[2] - 1)]);
	}
	else
	{
		ind = ((process->instr[3] << 8) & 0xFF00) | (process->instr[4] & 0xFF);
		arenacharge(vm,
				&process->regs[REG_SIZE * (process->instr[2] - 1)],
				((process->pc + (ind % IDX_MOD)) << 32) | REG_SIZE,
				process->player);
	}
	return (1);
}

unsigned char	*and_or_xor_loop(t_process *process, t_vm *vm, long long *val)
{
	unsigned char	*reg;
	char			*instr_cop;
	int				i;

	instr_cop = process->instr + 2;
	i = -1;
	while (++i < 2 && vm)
		if (((process->instr[1] >> (6 - (2 * i))) & 3) == REG_CODE)
		{
			reg = &(process->regs[(par_to_ll(instr_cop, 1) - 1) * REG_SIZE]);
			val[i] = par_to_ll((char *)reg, REG_SIZE);
			++instr_cop;
		}
		else if (((process->instr[1] >> (6 - (2 * i))) & 3) == DIR_CODE)
		{
			val[i] = par_to_ll(instr_cop, DIR_SIZE);
			instr_cop += DIR_SIZE;
		}
		else
		{
			val[i] = arena_to_ll(vm->arena,
				process->pc + (par_to_ll(instr_cop, IND_SIZE) % IDX_MOD));
			instr_cop += IND_SIZE;
		}
	return (&(process->regs[(par_to_ll(instr_cop, 1) - 1) * REG_SIZE]));
}
