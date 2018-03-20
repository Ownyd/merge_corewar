/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 01:59:48 by tlux              #+#    #+#             */
/*   Updated: 2018/03/18 19:35:33 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int		name_error(int err, char *tmp)
{
	free(tmp);
	if (err == 1)
		ft_putendl_fd(KRED"Champion's name isn't well formated."KNRM, 2);
	else if (err == 2)
		ft_putendl_fd(KRED"Duplicate champion's name."KNRM, 2);
	return (0);
}

int		comment_error(int err, char *tmp)
{
	free(tmp);
	if (err == 1)
		ft_putendl_fd(KRED"Champion's description isn't well formated."KNRM, 2);
	else if (err == 2)
		ft_putendl_fd(KRED"Duplicate champion's description."KNRM, 2);
	return (0);
}

int		label_error(int err)
{
	if (err == 1)
		ft_putendl_fd(KRED"Missing Label_char to define a Label."KNRM, 2);
	return (0);
}

int		line_error(int err)
{
	if (err == 1)
		ft_putendl_fd(KRED"Missing champion's name."KNRM, 2);
	else if (err == 2)
		ft_putendl_fd(KRED"Missing champion's description."KNRM, 2);
	return (0);
}

int		main_error(t_utils *utils)
{
	char *tmp;

	ft_putstr_fd("\033[1m"KRED"\tError at line [", 2);
	ft_putnbr_fd(utils->i, 2);
	ft_putstr_fd("] : \"", 2);
	tmp = ft_strtrim(utils->line);
	ft_putstr_fd(tmp, 2);
	ft_putendl_fd("\""KNRM, 2);
	ft_labeldel(&utils->label);
	ft_cmddel(&utils->cmds);
	ft_outputdel(&utils->output);
	free(utils->line);
	free(tmp);
	return (0);
}
