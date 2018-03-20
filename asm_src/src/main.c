/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:53:08 by tlux              #+#    #+#             */
/*   Updated: 2018/03/20 01:25:30 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static void	handle_params(char *line, t_utils *utils, int opc)
{
	int		i;
	char	**tmp;
	int		print;
	int		shift;
	int		ocs;

	ocs = utils->octet;
	ft_init_var(&print, &shift, &i);
	if (!(tmp = ft_strsplit(line, ",")))
		malloc_error();
	while (++i < 3 && tmp[i] != NULL)
	{
		if (tmp[i][0] == 'r' && ((utils->octet)++) >= 0)
			print += (1 << shift);
		else if (tmp[i][0] == '%' && ((utils->octet) += (opc == 1 || opc == 2 ||
				opc == 6 || opc == 7 || opc == 8 || opc == 13) ? 4 : 2) >= 0)
			print += (2 << shift);
		else if (((utils->octet) += 2) >= 0)
			print += (3 << shift);
		shift -= 2;
	}
	ft_tabfree(tmp);
	if ((i > 1 || opc == 16) && ((utils->octet)++))
		ft_outputadd(&(utils->output), ft_outputnew(print));
	opc_params(line, ocs, opc, utils);
}

static void	handle_commands(char *line, t_utils *utils)
{
	char	**tmp;
	int		opc;
	char	*tmps;

	if (!(tmp = ft_strsplit(line, "\t ")))
		malloc_error();
	if (tmp == NULL)
		return ;
	opc = identify_cmd(tmp[0], utils->cmds);
	tmps = ft_delspaces(line);
	ft_outputadd(&(utils->output), ft_outputnew(opc));
	handle_params(tmps + ft_strlen(tmp[0]), utils, opc);
	ft_tabfree(tmp);
	free(tmps);
}

static void	parse_line(char *line, t_utils *utils)
{
	int			i;

	i = 0;
	while (ft_strchr("\t ", line[i]))
		i++;
	while (ft_strchr(LABEL_CHARS, line[i]) && line[i] != '\0')
		i++;
	if (line[i] == LABEL_CHAR)
	{
		if (ft_isstrblank(line + i + 1) == 0)
		{
			handle_commands(line + i + 1, utils);
			(utils->octet)++;
		}
	}
	else
	{
		handle_commands(line, utils);
		(utils->octet)++;
	}
}

static int	asm_pilot(char *file)
{
	t_utils utils;

	utils = init_utils(file);
	if (utils.fatal == 1)
		return (0);
	while (get_next_line(utils.fd, &(utils.line)) == 1)
	{
		delete_comments(&(utils.line));
		if ((++(utils.i) >= 0) && !validity_line(&utils))
			return (main_error(&utils));
		if (!ft_isstrblank(utils.line) && !ft_strnstr(utils.line, ".name", 5)
	&& !ft_strnstr(utils.line, ".comment", 8))
			parse_line(utils.line, &utils);
		else if (ft_strnstr(utils.line, ".name", 5))
			add_infos((utils.line + 5), 0, 11, &utils);
		else if (ft_strnstr(utils.line, ".comment", 8))
			add_infos((utils.line + 8), 0, 12, &utils);
		add_infos(NULL, 0, 2, &utils);
		free(utils.line);
	}
	free(utils.line);
	return (end_utils(file, &utils));
}

int			main(int ac, char **av)
{
	int i;
	i = 1;
	if (ac == 1)
	{
		ft_putendl("usage : ./asm [files.cor]");
	}
	
	while (i < ac)
	{
		ft_putstr("--> Assembling : ["KBLU"\033[1m");
		ft_putstr(av[i]);
		ft_putstr(KNRM"]\n\t");
		asm_pilot(av[i]);
		i++;
	}
	return (0);
}
