/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 01:59:48 by tlux              #+#    #+#             */
/*   Updated: 2018/03/09 02:38:07 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int		name_error(int err, char *tmp)
{
	free(tmp);
	if (err == 1)
		ft_putendl_fd("Champion's name isn't well formated.", 2);
	else if (err == 2)
		ft_putendl_fd("Duplicate champion's name.", 2);
	return (0);
}

int		comment_error(int err, char *tmp)
{
	free(tmp);
	if (err == 1)
		ft_putendl_fd("Champion's description isn't well formated.", 2);
	else if (err == 2)
		ft_putendl_fd("Duplicate champion's description.", 2);
	return (0);
}

int		label_error(int err)
{
	if (err == 1)
		ft_putendl_fd("Missing Label_char to define a Label.", 2);
	else if (err == 2)
		ft_putendl_fd("Missing Tabulation after Label.", 2);
	return (0);
}

int		line_error(int err)
{
	store_label(NULL, 0, 3);
	commandlist(NULL, 2);
	store_output(0, 3, 0);
	if (err == 1)
		ft_putendl_fd("Missing champion's name.", 2);
	else if (err == 2)
		ft_putendl_fd("Missing champion's description.", 2);
	return (0);
}

void	main_error(char *line, int i)
{
	char *tmp;

	ft_putstr_fd("Error at line [", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd("] : \"", 2);
	tmp = ft_strtrim(line);
	ft_putstr_fd(tmp, 2);
	ft_putendl_fd("\"", 2);
	free(line);
	free(tmp);
	exit(1);
}
