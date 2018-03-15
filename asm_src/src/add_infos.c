/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 00:46:54 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 15:52:09 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	put_header(t_header header)
{
	int i;

	i = -1;
	print_bits(header.magic, 4);
	while (++i < PROG_NAME_LENGTH)
		store_output((header.prog_name)[i], 1, 0);
	i = -1;
	print_bits(0, 4);
	print_bits(header.prog_size, 4);
	while (++i < COMMENT_LENGTH)
		store_output((header.comment)[i], 1, 0);
	print_bits(0, 4);
}

int		get_fd(int cmd, int fd)
{
	static int fdstore;

	if (cmd == 1)
		fdstore = fd;
	else if (cmd == 2)
		return (fdstore);
	return (fdstore);
}

void	get_name(t_header *header, char *line)
{
	int		i;
	char	*buf;
	char	*read;

	buf = line[1] ? ft_strsub(line, 1, ft_strlen(line) - 1) : ft_strdup("\0");
	if (!(line[0] == '"' &&
				line[ft_strlen(line) - 1] == '"' && ft_strlen(line) != 1))
	{
		buf = ft_strfreejoin(buf, "\n", 1);
		while ((i = 0) == 0 && get_next_line(get_fd(2, 0), &read) == 1)
		{
			while (read[i] != '\0' && read[i] != '"')
				i++;
			buf = ft_strfreejoin(buf, ft_strsub(read, 0, i), 3);
			if (read[i] == '"')
				break ;
			buf = ft_strfreejoin(buf, "\n", 1);
			free(read);
		}
		free(read);
	}
	else
		buf[ft_strlen(buf) - 1] = '\0';
	ft_strcpy(header->prog_name, buf);
	free(buf);
}

void	get_comment(t_header *header, char *line)
{
	int		i;
	char	*buf;
	char	*read;

	buf = line[1] ? ft_strsub(line, 1, ft_strlen(line) - 1) : ft_strdup("\0");
	if (!(line[0] == '"' &&
				line[ft_strlen(line) - 1] == '"' && ft_strlen(line) != 1))
	{
		buf = ft_strfreejoin(buf, "\n", 1);
		while ((i = 0) == 0 && get_next_line(get_fd(2, 0), &read) == 1)
		{
			while (read[i] != '\0' && read[i] != '"')
				i++;
			buf = ft_strfreejoin(buf, ft_strsub(read, 0, i), 3);
			if (read[i] == '"')
				break ;
			buf = ft_strfreejoin(buf, "\n", 1);
			free(read);
		}
		free(read);
	}
	else
		buf[ft_strlen(buf) - 1] = '\0';
	ft_strcpy(header->comment, buf);
	free(buf);
}

int		add_infos(char *info, char *line, int size, int cmd)
{
	static t_header header;
	int				i;
	static int		state = 0;
	char			*tmp;
	int				tmpi;

	if (cmd == 1 && (i = 0) == 0)
		tmp = ft_strtrim(line);
	if (cmd == 0 && (header.prog_size = size) == (unsigned int)size)
		header.magic = COREWAR_EXEC_MAGIC;
	else if (cmd == 1 && ft_strcmp(info, "name") == 0 && (++state))
		get_name(&header, tmp);
	else if (cmd == 1 && ft_strcmp(info, "comment") == 0 && (++state))
		get_comment(&header, tmp);
	else if (cmd == 2 && state == 2 && (state = 3) == 3)
	{
		tmpi = (int)lseek(get_fd(2, 0), 0, SEEK_CUR);
		first_parse(get_fd(2, 0));
		lseek(get_fd(2, 0), tmpi, SEEK_SET);
		put_header(header);
	}
	if (cmd == 1)
		free(tmp);
	return (0);
}
