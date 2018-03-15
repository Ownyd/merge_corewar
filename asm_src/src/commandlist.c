/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:06:27 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:29:14 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static int	identify_cmd(char *cmd, t_cmds *lst)
{
	t_cmds *tmp;

	tmp = lst;
	while (tmp)
	{
		if (ft_strcmp(cmd, tmp->cmd) == 0)
			return (tmp->opc);
		tmp = tmp->next;
	}
	return (-1);
}

int			commandlist(char *cmd, int todo)
{
	static t_cmds *lst = NULL;

	if (todo == 1)
		return (identify_cmd(cmd, lst));
	if (todo == 2)
		ft_cmddel(&lst);
	if (todo == 2)
		return (0);
	ft_cmdadd(&lst, ft_cmdnew("live", 1));
	ft_cmdadd(&lst, ft_cmdnew("ld", 2));
	ft_cmdadd(&lst, ft_cmdnew("st", 3));
	ft_cmdadd(&lst, ft_cmdnew("add", 4));
	ft_cmdadd(&lst, ft_cmdnew("sub", 5));
	ft_cmdadd(&lst, ft_cmdnew("and", 6));
	ft_cmdadd(&lst, ft_cmdnew("or", 7));
	ft_cmdadd(&lst, ft_cmdnew("xor", 8));
	ft_cmdadd(&lst, ft_cmdnew("zjmp", 9));
	ft_cmdadd(&lst, ft_cmdnew("ldi", 10));
	ft_cmdadd(&lst, ft_cmdnew("sti", 11));
	ft_cmdadd(&lst, ft_cmdnew("fork", 12));
	ft_cmdadd(&lst, ft_cmdnew("lld", 13));
	ft_cmdadd(&lst, ft_cmdnew("lldi", 14));
	ft_cmdadd(&lst, ft_cmdnew("lfork", 15));
	ft_cmdadd(&lst, ft_cmdnew("aff", 16));
	return (0);
}
