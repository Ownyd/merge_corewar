/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:50:03 by emarin            #+#    #+#             */
/*   Updated: 2018/03/07 22:16:55 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	ft_overflow(char *str)
{
	if (((long long)ft_atoi(str) != ft_atoi_l(str))
	|| ft_strlen(str) > 11)
		return (0);
	return (1);
}

char	ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		++i;
	return ((str[i]) ? 0 : 1);
}

int		ft_er(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (0);
}

int		usage(int code)
{
	ft_putstr_fd("usage:\n", STDERR_FILENO);
	ft_putstr_fd("./corewar -[Vncurses] [-dump nbr_cycles] ", STDERR_FILENO);
	ft_putstr_fd("[[-n number] champion1.cor]\n", STDERR_FILENO);
	return (code);
}

int		close_vm(t_vm *vm, int code)
{
	if (vm->arena)
		free(vm->arena);
	if (vm->players)
		free(vm->players);
	free_all_process(vm->process);
	return (code);
}
