/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:57:02 by emarin            #+#    #+#             */
/*   Updated: 2018/03/07 21:42:24 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_process(t_process *process)
{
	int	i;

	i = 0;
	ft_printf("v-----process-----v\n");
	ft_printf("carry=%d\n", process->carry);
	ft_printf("nblive=%d\n", process->nblive);
	ft_printf("pc= %lld", process->pc);
	ft_printf("reg=\n");
	i = -1;
	while (++i < REG_NUMBER)
	{
		ft_printf("\tr%d= \n", i + 1);
		reg_print(&(process->regs)[i * REG_SIZE]);
	}
	ft_printf("^-----process-----^\n");
}

char	add_process(t_process **process, long long pc, long long num_player,
		int player)
{
	t_process *new_p;

	if (!(new_p = (t_process *)malloc(sizeof(t_process))))
		return (ft_er("malloc error\n"));
	ft_bzero(new_p->regs, REG_NUMBER * REG_SIZE);
	reg_charge(new_p->regs, num_player);
	new_p->pc = pc;
	new_p->player = player;
	new_p->carry = 0;
	new_p->nblive = 0;
	new_p->cycles = 0;
	new_p->next = NULL;
	new_p->instr = NULL;
	if (*process != NULL)
		new_p->next = *process;
	*process = new_p;
	return (1);
}

char	fork_process(t_process **process, long long pc, t_process *to_fork,
		t_vm *vm)
{
	t_process	*new_p;
	int			i;

	if (!(new_p = (t_process *)malloc(sizeof(t_process))))
		return (ft_er("malloc error\n"));
	i = -1;
	while (++i < REG_NUMBER)
		reg_clone(&(new_p->regs)[i * REG_SIZE], &(to_fork->regs)[i * REG_SIZE]);
	pc = pc % MEM_SIZE;
	if (pc < 0)
		pc += MEM_SIZE;
	new_p->pc = pc;
	new_p->player = to_fork->player;
	new_p->carry = to_fork->carry;
	new_p->nblive = to_fork->nblive;
	new_p->cycles = to_fork->cycles;
	new_p->next = *process;
	new_p->instr = NULL;
	charge_name_instr(new_p, vm);
	*process = new_p;
	return (1);
}

void	remove_process(t_process **process, t_process *to_del)
{
	t_process	*tmp;

	if (*process && *process == to_del)
	{
		*process = (*process)->next;
		free(to_del->instr);
		free(to_del);
		return ;
	}
	tmp = *process;
	while (tmp && tmp->next && tmp->next != to_del)
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->next == to_del)
	{
		tmp->next = (tmp->next)->next;
		free(to_del->instr);
		free(to_del);
	}
}

void	free_all_process(t_process *process)
{
	t_process	*tmp;

	while (process)
	{
		tmp = process;
		process = process->next;
		free(tmp->instr);
		free(tmp);
	}
}
