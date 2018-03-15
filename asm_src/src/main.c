/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:53:08 by tlux              #+#    #+#             */
/*   Updated: 2018/03/09 03:13:03 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static void	handle_params(char *line, int *octet, int opc)
{
	int		i;
	char	**tmp;
	int		print;
	int		shift;
	int		ocs;

	ocs = *octet;
	ft_init_var(&print, &shift, &i);
	tmp = ft_strsplit(line, ",");
	while (++i < 3 && tmp[i] != NULL)
	{
		if (tmp[i][0] == 'r' && ((*octet)++) >= 0)
			print += (1 << shift);
		else if (tmp[i][0] == '%' && ((*octet) += (opc == 1 || opc == 2 ||
				opc == 6 || opc == 7 || opc == 8 || opc == 13) ? 4 : 2) >= 0)
			print += (2 << shift);
		else if (((*octet) += 2) >= 0)
			print += (3 << shift);
		shift -= 2;
	}
	ft_tabfree(tmp);
	if ((i > 1 || opc == 16) && ((*octet)++))
		store_output(print, 1, 0);
	opc_params(line, ocs, opc);
}

static void	handle_commands(char *line, int *octet)
{
	char	**tmp;
	int		opc;
	char	*tmps;

	tmp = ft_strsplit(line, "\t ");
	if (tmp == NULL)
		return ;
	opc = commandlist(tmp[0], 1);
	tmps = ft_delspaces(line);
	store_output(opc, 1, 0);
	handle_params(tmps + ft_strlen(tmp[0]), octet, opc);
	ft_tabfree(tmp);
	free(tmps);
}

static void	parse_line(char *line)
{
	static int	octet = 0;
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
			handle_commands(line + i + 1, &octet);
			octet++;
		}
	}
	else
	{
		handle_commands(line, &octet);
		octet++;
	}
}

int			main(int ac, char **av)
{
	int			fd;
	char		*line;
	static int	i = -1;

	fd = init_utils(ac, av);
	while (get_next_line(get_fd(2, 0), &line) == 1)
	{
		delete_comments(&line);
		if ((++i >= 0) && !validity_line(line))
			main_error(line, i);
		if (ft_isstrblank(line) == 0 && !ft_strnstr(line, ".name", 5) &&
				!ft_strnstr(line, ".comment", 8))
			parse_line(line);
		else if (ft_strnstr(line, ".name", 5))
			add_infos("name", line + 5, 0, 1);
		else if (ft_strnstr(line, ".comment", 8))
			add_infos("comment", line + 8, 0, 1);
		add_infos(NULL, NULL, 0, 2);
		free(line);
	}
	free(line);
	return (end_utils(ac, av));
}
