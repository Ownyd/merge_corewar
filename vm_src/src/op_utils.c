/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:46:44 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/07 17:32:42 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long long	par_to_ll(char *param, int par_size)
{
	long long	res;
	int			neg;
	int			i;

	res = 0;
	i = 0;
	neg = ((param[0] & 0x80) == 0x80);
	while (i < par_size)
	{
		res = res << 8;
		res = (neg) ? res | (~param[i] & 0xFF) : res | (param[i] & 0xFF);
		++i;
	}
	if (neg)
		res = (res + 1) * -1;
	return (res);
}

t_op		*get_op_by_id(unsigned char index)
{
	int	i;

	i = 0;
	while (g_op[i].index != index && g_op[i].index != 0)
	{
		i++;
	}
	if (g_op[i].index == 0)
		return (NULL);
	return ((t_op*)&g_op[i]);
}

int			size_instr(char instr, char *arg)
{
	t_op	*operateur;
	int		i;
	int		j;

	if (!arg || !(operateur = get_op_by_id(instr)))
		return (0);
	j = 1;
	if (operateur->ocp)
		j++;
	i = 0;
	while (operateur->ocp && i < operateur->opcode)
	{
		j += ((arg[0] >> ((3 - i) * 2) & 3) == REG_CODE) ? 1 : 0;
		j += ((arg[0] >> ((3 - i) * 2) & 3) == DIR_CODE) ?
			4 - (2 * operateur->dir_size) : 0;
		j += ((arg[0] >> ((3 - i) * 2) & 3) == IND_CODE) ? IND_SIZE : 0;
		i++;
	}
	if (!operateur->ocp)
		j += (4 - (2 * operateur->dir_size)) * operateur->opcode;
	return (j);
}

long long	get_param(int nb, t_process *process, char *arena, int *i)
{
	unsigned char	*reg;
	long long		ret;

	if (((process->instr[1] >> (6 - (2 * nb))) & 3) == REG_CODE)
	{
		reg = &(process->regs[(par_to_ll(&process->instr[*i]
						, 1) - 1) * REG_SIZE]);
		ret = par_to_ll((char *)reg, REG_SIZE);
		*i += 1;
	}
	else if (((process->instr[1] >> (6 - (2 * nb))) & 3) == DIR_CODE)
	{
		ret = par_to_ll(&process->instr[*i]
				, 4 - (2 * get_op_by_id(process->instr[0])->dir_size));
		*i += 4 - (2 * get_op_by_id(process->instr[0])->dir_size);
	}
	else
	{
		ret = arena_to_ll(arena, process->pc
				+ (par_to_ll(&process->instr[*i], IND_SIZE) % IDX_MOD));
		*i += IND_SIZE;
	}
	return (ret);
}
