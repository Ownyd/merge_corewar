/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 00:46:54 by tlux              #+#    #+#             */
/*   Updated: 2018/03/18 19:35:25 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static void	put_header(t_utils *utils)
{
	int i;

	i = -1;
	print_bits(utils, utils->header.magic, 4);
	while (++i < PROG_NAME_LENGTH)
		ft_outputadd(&(utils->output),
				ft_outputnew((utils->header.prog_name)[i]));
	i = -1;
	print_bits(utils, 0, 4);
	print_bits(utils, utils->header.prog_size, 4);
	while (++i < COMMENT_LENGTH)
		ft_outputadd(&(utils->output),
				ft_outputnew((utils->header.comment)[i]));
	print_bits(utils, 0, 4);
}

static char	*read_buf(char *buf, t_utils *utils)
{
	int		i;
	char	*read;

	if (!(buf = ft_strfreejoin(buf, "\n", 1)))
		malloc_error();
	while ((i = 0) == 0 && get_next_line(utils->fd, &read) == 1)
	{
		while (read[i] != '\0' && read[i] != '"')
			i++;
		if (!(buf = ft_strfreejoin(buf, ft_strsub(read, 0, i), 3)))
			malloc_error();
		if (read[i] == '"')
			break ;
		if (!(buf = ft_strfreejoin(buf, "\n", 1)))
			malloc_error();
		free(read);
	}
	free(read);
	return (buf);
}

static void	get_name(t_utils *utils, char *line)
{
	char	*buf;

	buf = line[1] ? ft_strsub(line, 1, ft_strlen(line) - 1) : ft_strdup("\0");
	if (buf == NULL)
		malloc_error();
	if (!(line[0] == '"' &&
				line[ft_strlen(line) - 1] == '"' && ft_strlen(line) != 1))
		buf = read_buf(buf, utils);
	else
		buf[ft_strlen(buf) - 1] = '\0';
	ft_strcpy((&(utils->header))->prog_name, buf);
	free(buf);
}

static void	get_comment(t_utils *utils, char *line)
{
	char	*buf;

	buf = line[1] ? ft_strsub(line, 1, ft_strlen(line) - 1) : ft_strdup("\0");
	if (buf == NULL)
		malloc_error();
	if (!(line[0] == '"' &&
				line[ft_strlen(line) - 1] == '"' && ft_strlen(line) != 1))
		buf = read_buf(buf, utils);
	else
		buf[ft_strlen(buf) - 1] = '\0';
	ft_strcpy((&(utils->header))->comment, buf);
	free(buf);
}

int			add_infos(char *line, int size, int cmd, t_utils *utils)
{
	char			*tmp;
	int				tmpseek;

	if (cmd == 11 || cmd == 12)
		if (!(tmp = ft_strtrim(line)))
			malloc_error();
	if (cmd == 0 && (utils->header.prog_size = size) == (unsigned int)size)
		utils->header.magic = COREWAR_EXEC_MAGIC;
	else if (cmd == 11 && (++(utils->state)))
		get_name(utils, tmp);
	else if (cmd == 12 && (++(utils->state)))
		get_comment(utils, tmp);
	else if (cmd == 2 && utils->state == 2 && (utils->state = 3) == 3)
	{
		tmpseek = (int)lseek(utils->fd, 0, SEEK_CUR);
		first_parse(utils);
		lseek(utils->fd, tmpseek, SEEK_SET);
		put_header(utils);
	}
	if (cmd == 11 || cmd == 12)
		free(tmp);
	return (0);
}
