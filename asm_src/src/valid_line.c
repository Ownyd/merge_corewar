/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:20:52 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 16:01:41 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int			validity_name(char *line, int *name)
{
	int		i;
	char	*tmp;
	int		seek;

	seek = lseek(get_fd(2, 0), 0, SEEK_CUR);
	i = 1;
	tmp = ft_strtrim(line);
	if (tmp[0] != '"')
		return (name_error(1, tmp));
	while (tmp[i] != '\0' && tmp[i] != '"')
		i++;
	if (tmp[i] == '"' && i > 129)
		return (name_error(1, tmp));
	if (tmp[i] == '\0')
		i = read_in_field(i, 129);
	if (i > 129)
		return (name_error(1, tmp));
	if (*name == 1)
		return (name_error(2, tmp));
	*name = 1;
	lseek(get_fd(2, 0), seek, SEEK_SET);
	free(tmp);
	return (1);
}

int			validity_com(char *line, int *com)
{
	int		i;
	char	*tmp;
	int		seek;

	seek = lseek(get_fd(2, 0), 0, SEEK_CUR);
	i = 1;
	tmp = ft_strtrim(line);
	if (tmp[0] != '"')
		return (comment_error(1, tmp));
	while (tmp[i] != '\0' && tmp[i] != '"')
		i++;
	if (tmp[i] == '"' && i > 2049)
		return (comment_error(1, tmp));
	if (tmp[i] == '\0')
		i = read_in_field(i, 2049);
	if (i > 2049)
		return (comment_error(1, tmp));
	if (*com == 1)
		return (comment_error(2, tmp));
	*com = 1;
	lseek(get_fd(2, 0), seek, SEEK_SET);
	free(tmp);
	return (1);
}

int			validity_opc(char *line)
{
	char	*tmp;
	char	**tmpt;
	int		opc;

	tmp = ft_strtrim(line);
	tmpt = ft_strsplit(line, " \t");
	if ((opc = commandlist(tmpt[0], 1)) == -1)
	{
		free(tmp);
		ft_putendl_fd("This opcode doesn't exist.", 2);
		ft_tabfree(tmpt);
		return (0);
	}
	else if (!validity_params(opc, tmp + ft_strlen(tmpt[0])))
	{
		free(tmp);
		ft_tabfree(tmpt);
		return (0);
	}
	free(tmp);
	ft_tabfree(tmpt);
	return (1);
}

int			validity_label(char *line)
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
		if (!validity_opc(tmp))
			return (0);
	return (1);
}

int			validity_line(char *line)
{
	static int name = 0;
	static int com = 0;

	if (ft_strnstr(line, ".name", 5) &&
			!validity_name(line + 5, &name))
		return (line_error(0));
	else if (ft_strnstr(line, ".comment", 8) &&
			!validity_com(line + 8, &com))
		return (line_error(0));
	else if (!ft_strnstr(line, ".comment", 8) &&
			!ft_strnstr(line, ".name", 5) && !ft_isstrblank(line))
	{
		if (name != 1)
			return (line_error(1));
		else if (com != 1)
			return (line_error(2));
		else if (!validity_command_line(line))
			return (line_error(0));
	}
	return (1);
}
