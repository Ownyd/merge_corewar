/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 01:20:09 by tlux              #+#    #+#             */
/*   Updated: 2018/03/18 19:20:21 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	malloc_error(void)
{
	ft_putendl_fd(KRED"FATAL :Malloc error."KNRM, 2);
	exit(1);
}

int		reg_error(int err)
{
	if (err == 1)
		ft_putendl_fd(KRED"This register doesn't exist."KNRM, 2);
	else if (err == 2)
		ft_putendl_fd(KRED"Bad parameter (Register)."KNRM, 2);
	return (0);
}

int		dir_error(int err)
{
	if (err == 1)
		ft_putendl_fd(KRED"Bad parameter (Direct)."KNRM, 2);
	if (err == 2)
		ft_putendl_fd(KRED"This label doesn't exist."KNRM, 2);
	if (err == 3)
		ft_putendl_fd(KRED"Invalid direct value."KNRM, 2);
	return (0);
}

int		indir_error(int err)
{
	if (err == 1)
		ft_putendl_fd(KRED"Bad parameter (Indirect)."KNRM, 2);
	if (err == 2)
		ft_putendl_fd(KRED"This label doesn't exist."KNRM, 2);
	if (err == 3)
		ft_putendl_fd(KRED"Invalid indirect value."KNRM, 2);
	return (0);
}

int		param_error(int err, char **todel)
{
	if (todel)
		ft_tabfree(todel);
	if (err == 1)
		ft_putendl_fd(KRED"Wrong number of parameter for this instruction."
				KNRM, 2);
	if (err == 2)
		ft_putendl_fd(KRED"Extra characters in the line."KNRM, 2);
	return (0);
}
