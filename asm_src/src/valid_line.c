/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:20:52 by tlux              #+#    #+#             */
/*   Updated: 2018/03/21 18:50:30 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static int		validity_name(char *line, t_utils *utils)
{
	int		i;
	char	*tmp;
	int		seek;

	seek = lseek(utils->fd, 0, SEEK_CUR);
	i = 1;
	tmp = ft_strtrim(line);
	if (tmp[0] != '"' || ft_strocur(tmp, '"') > 2)
		return (name_error(1, tmp));
	while (tmp[i] != '\0' && tmp[i] != '"')
		i++;
	if (tmp[i] == '"' && i > 129)
		return (name_error(1, tmp));
	if (tmp[i] == '\0')
		i = read_in_field(i, 129, utils->fd);
	else if (!ft_isstrblank(tmp + i + 1))
		return (name_error(1, tmp));
	if (i > 129)
		return (name_error(1, tmp));
	if (utils->name == 1)
		return (name_error(2, tmp));
	utils->name = 1;
	lseek(utils->fd, seek, SEEK_SET);
	free(tmp);
	return (1);
}

static int		validity_com(char *line, t_utils *utils)
{
	int		i;
	char	*tmp;
	int		seek;

	seek = lseek(utils->fd, 0, SEEK_CUR);
	i = 1;
	tmp = ft_strtrim(line);
	if (tmp[0] != '"' || ft_strocur(tmp, '"') > 2)
		return (comment_error(1, tmp));
	while (tmp[i] != '\0' && tmp[i] != '"')
		i++;
	if (tmp[i] == '"' && i > 2049)
		return (comment_error(1, tmp));
	if (tmp[i] == '\0')
		i = read_in_field(i, 2049, utils->fd);
	else if (!ft_isstrblank(tmp + i + 1))
		return (comment_error(1, tmp));
	if (i > 2049)
		return (comment_error(1, tmp));
	if (utils->com == 1)
		return (comment_error(2, tmp));
	utils->com = 1;
	lseek(utils->fd, seek, SEEK_SET);
	free(tmp);
	return (1);
}

int				validity_opc(char *line, t_utils utils)
{
	char	*tmp;
	char	**tmpt;
	int		opc;

	if (!(tmp = ft_strtrim(line)))
		malloc_error();
	if (!(tmpt = ft_strsplit(line, " \t")))
		malloc_error();
	if ((opc = identify_cmd(tmpt[0], utils.cmds)) == -1)
	{
		free(tmp);
		ft_putendl_fd(KRED"This opcode doesn't exist."KNRM, 2);
		ft_tabfree(tmpt);
		return (0);
	}
	else if (!validity_params(opc, tmp + ft_strlen(tmpt[0]), utils))
	{
		free(tmp);
		ft_tabfree(tmpt);
		return (0);
	}
	free(tmp);
	ft_tabfree(tmpt);
	return (1);
}

int				validity_label(char *line, t_utils utils)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_strchr("\t ", line[i]) && line[i] != '\0')
		i++;
	while (ft_strchr(LABEL_CHARS, line[i]) && line[i] != '\0')
		i++;
	if (line[i] != ':')
		return (label_error(1));
	tmp = line + i + 1;
	if (!ft_isstrblank(tmp))
		if (!validity_opc(tmp, utils))
			return (0);
	return (1);
}

int				validity_line(t_utils *utils)
{
	if (ft_strnstr(utils->line, ".name", 5) &&
			!validity_name((utils->line + 5), utils))
		return (0);
	else if (ft_strnstr(utils->line, ".comment", 8) &&
			!validity_com((utils->line + 8), utils))
		return (0);
	else if (!ft_strnstr(utils->line, ".comment", 8) && (utils->line)[0] != '.' &&
			!ft_strnstr(utils->line, ".name", 5) && !ft_isstrblank(utils->line))
	{
		if (utils->name != 1)
			return (line_error(1));
		else if (utils->com != 1)
			return (line_error(2));
		else if (!validity_command_line(utils->line, *utils))
			return (0);
	}
	else if (!ft_strnstr(utils->line, ".comment", 8) && (utils->line)[0] == '.' &&
			!ft_strnstr(utils->line, ".name", 5) && !ft_isstrblank(utils->line))
	{
		ft_putstr("Ignored command : \"");
		ft_putstr(utils->line);
		ft_putstr("\"\n\t");
	}
	return (1);
}
