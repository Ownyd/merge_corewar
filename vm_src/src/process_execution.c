/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:05:17 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/08 23:04:21 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_ocp(int ocp, int arg[4], int size)
{
	int	test;
	int	i;

	i = 0;
	while (i < size)
	{
		if (!(test = (ocp >> ((3 - i) * 2)) & 3))
			return (0);
		if (test == REG_CODE && !(arg[i] & T_REG))
			return (0);
		if (test == IND_CODE && !(arg[i] & T_IND))
			return (0);
		if (test == DIR_CODE && !(arg[i] & T_DIR))
			return (0);
		i++;
	}
	return (1);
}

int		check_validity(char *instr)
{
	t_op	*operateur;
	int		i;
	int		j;

	if (!(operateur = get_op_by_id(instr[0])))
		return (0);
	j = 1;
	if (operateur->ocp && j++
			&& !check_ocp(instr[1], operateur->arg, operateur->opcode))
		return (0);
	i = 0;
	while (operateur->ocp && i < operateur->opcode)
	{
		if (((instr[1] >> ((3 - i) * 2)) & 3) == REG_CODE)
		{
			if (instr[j] <= 0 || instr[j] > REG_NUMBER)
				return (0);
			j++;
		}
		j += (((instr[1] >> ((3 - i) * 2)) & 3) == DIR_CODE) ?
			4 - (2 * operateur->dir_size) : 0;
		j += (((instr[1] >> ((3 - i) * 2)) & 3) == IND_CODE) ? IND_SIZE : 0;
		i++;
	}
	return (1);
}

char	charge_name_instr(t_process *process, t_vm *vm)
{
	if (!process->instr)
	{
		if (get_op_by_id(vm->arena[process->pc % MEM_SIZE]))
		{
			if (!(process->instr = malloc(1)))
				return (ft_er("malloc error\n"));
			process->instr[0] = vm->arena[process->pc % MEM_SIZE];
			process->cycles = get_op_by_id(process->instr[0])->cycles - 1;
		}
		else
			process->cycles = 0;
	}
	return (1);
}

char	charge_instr(t_process *process, t_vm *vm)
{
	int		size;
	char	instr;

	if (process->instr)
	{
		instr = process->instr[0];
		ft_strdel(&process->instr);
		if ((size = size_instr(instr
		, &vm->arena[(process->pc + 1) % MEM_SIZE])))
		{
			if (!(process->instr = malloc(size)))
				return (ft_er("malloc error\n"));
			ft_arenacpy((unsigned char*)process->instr, vm->arena,
					process->pc, size);
			process->instr[0] = instr;
		}
	}
	return (1);
}

char	process_execution(t_process *process, t_vm *vm)
{
	int	(*f)(t_process *process, t_vm *vm);
	int	pc_incr;
	int	size;

	pc_incr = 1;
	if (process->cycles-- > 0)
		return (1);
	if (!charge_instr(process, vm))
		return (0);
	size = (process->instr) ? size_instr(process->instr[0]
	, &process->instr[1]) : 0;
	if (process->instr && check_validity(process->instr))
	{
		f = get_op_by_id(process->instr[0])->fonct;
		pc_incr = f(process, vm);
	}
	process->pc += (size && pc_incr) ? size : 1;
	process->pc = process->pc % MEM_SIZE;
	ft_strdel(&process->instr);
	return (1);
}
