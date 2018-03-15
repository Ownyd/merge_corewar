/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 01:20:09 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:30:06 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int	reg_error(int err)
{
	store_label(NULL, 0, 3);
	commandlist(NULL, 2);
	store_output(0, 3, 0);
	if (err == 1)
		ft_putendl_fd("This register doesn't exist.", 2);
	else if (err == 2)
		ft_putendl_fd("Bad parameter (Register).", 2);
	return (0);
}

int	dir_error(int err)
{
	store_label(NULL, 0, 3);
	commandlist(NULL, 2);
	store_output(0, 3, 0);
	if (err == 1)
		ft_putendl_fd("Bad parameter (Direct).", 2);
	if (err == 2)
		ft_putendl_fd("This label doesn't exist.", 2);
	if (err == 3)
		ft_putendl_fd("Overflow of a direct value.", 2);
	return (0);
}

int	indir_error(int err)
{
	store_label(NULL, 0, 3);
	commandlist(NULL, 2);
	store_output(0, 3, 0);
	if (err == 1)
		ft_putendl_fd("Bad parameter (Indirect).", 2);
	if (err == 2)
		ft_putendl_fd("This label doesn't exist.", 2);
	if (err == 3)
		ft_putendl_fd("Overflow of an indirect value.", 2);
	return (0);
}

int	param_error(int err, char **todel)
{
	store_label(NULL, 0, 3);
	commandlist(NULL, 2);
	store_output(0, 3, 0);
	if (todel)
		ft_tabfree(todel);
	if (err == 1)
		ft_putendl_fd("Too many parameters for this instruction.", 2);
	if (err == 2)
		ft_putendl_fd("Extra characters at the end of the line.", 2);
	return (0);
}
