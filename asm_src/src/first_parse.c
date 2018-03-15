/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:36:57 by tlux              #+#    #+#             */
/*   Updated: 2018/03/09 02:30:35 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static void	opc_nbr(char *params, int opc, int *octet)
{
	int		i;
	char	**tmpt;

	i = -1;
	tmpt = ft_strsplit(params, ",");
	while (++i < 3 && tmpt[i])
		if (tmpt[i][0] == 'r')
			(*octet)++;
		else if (tmpt[i][0] == '%')
			(*octet) += (opc == 1 || opc == 2 || opc == 6 || opc == 7 ||
					opc == 8 || opc == 13) ? 4 : 2;
		else
			(*octet) += 2;
	if (i > 1 || opc == 16)
		(*octet)++;
	ft_tabfree(tmpt);
}

static void	first_handle_commands(char *line, int *octet)
{
	char	**tmp;
	int		opc;
	char	*tmps;

	tmp = ft_strsplit(line, "\t ");
	if (tmp == NULL)
		return ;
	opc = commandlist(tmp[0], 1);
	tmps = ft_delspaces(line);
	opc_nbr(tmps + ft_strlen(tmp[0]), opc, octet);
	ft_tabfree(tmp);
	free(tmps);
}

static int	first_parse_line(char *line)
{
	static int	octet = 0;
	int			i;
	char		*tmp;

	i = 0;
	while (ft_strchr(LABEL_CHARS, line[i]) && line[i] != '\0')
		i++;
	if (line[i] == LABEL_CHAR)
	{
		tmp = ft_strsub(line, 0, i);
		store_label(tmp, octet, 1);
		free(tmp);
		if (ft_isstrblank(line + i + 1) == 0)
		{
			first_handle_commands(line + i + 1, &octet);
			octet++;
		}
	}
	else
	{
		first_handle_commands(line, &octet);
		octet++;
	}
	return (octet);
}

void		delete_comments(char **line)
{
	int		i;
	char	*ret;

	i = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '#')
		i++;
	if ((*line)[i] == '#')
	{
		ret = ft_strsub(*line, 0, i);
		free(*line);
		*line = ret;
	}
}

void		first_parse(int fd)
{
	int		prog_size;
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strtrim(line);
		free(line);
		delete_comments(&tmp);
		line = tmp;
		if (ft_isstrblank(line) == 0 && !ft_strnstr(line, ".name", 5)
				&& !ft_strnstr(line, ".comment", 8))
			prog_size = first_parse_line(line);
		free(line);
	}
	free(line);
	add_infos("size", NULL, prog_size, 0);
}
