/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 02:25:30 by tlux              #+#    #+#             */
/*   Updated: 2018/03/20 01:23:49 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static int		test_av(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (i <= 2 || av[i - 1] != 's' || av[i - 2] != '.')
	{
		ft_putendl_fd(KRED"FATAL :This is not a corewar file"KNRM, 2);
		return (0);
	}
	return (1);
}

static int		create_file(char *av)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	while (av[i] != '\0')
		i++;
	av[i - 1] = '\0';
	if (!(tmp = ft_strjoin(av, "cor")))
		malloc_error();
	if ((fd = open(tmp, O_TRUNC | O_CREAT | O_RDWR, 0755)) != -1)
	{
		ft_putstr(KGRN"Writing output program to ");
		ft_putendl(tmp);
		ft_putstr(KNRM"");
	}
	free(tmp);
	return (fd);
}

static t_utils	create_struct(int fd, int fatal)
{
	t_utils utils;

	utils.i = -1;
	utils.octet = 0;
	utils.fd = fd;
	utils.line = NULL;
	utils.state = 0;
	utils.name = 0;
	utils.com = 0;
	ft_bzero(utils.header.prog_name, 128);
	ft_bzero(utils.header.comment, 2048);
	utils.cmds = fatal == 1 ? NULL : init_commands();
	utils.label = NULL;
	utils.output = NULL;
	utils.fatal = fatal;
	return (utils);
}

t_utils			init_utils(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd(KRED"FATAL :The file doesn't exist"KNRM, 2);
		return (create_struct(fd, 1));
	}
	if (IND_SIZE != 2 || REG_SIZE != 4 || DIR_SIZE != 4 || REG_CODE != 1 ||
	DIR_CODE != 2 || IND_CODE != 3 || COMMENT_CHAR != '#' ||
	LABEL_CHAR != ':' || DIRECT_CHAR != '%' || REG_NUMBER != 16 ||
	ft_strcmp(NAME_CMD_STRING, ".name") || ft_strcmp(LABEL_CHARS,
	"abcdefghijklmnopqrstuvwxyz_0123456789") || T_IND != 4 ||
	ft_strcmp(COMMENT_CMD_STRING, ".comment") || T_REG != 1 || T_DIR != 2)
	{
		ft_putendl_fd(KRED"FATAL :Op.h header file was changed"KNRM, 2);
		return (create_struct(fd, 1));
	}
	if (!test_av(file))
		return (create_struct(fd, 1));
	return (create_struct(fd, 0));
}

int				end_utils(char *file, t_utils *utils)
{
	int fd;

	fd = -1;
	if ((fd = create_file(file)) < 0)
		ft_putendl_fd(KRED"ERROR :Unable to create .cor file"KNRM, 2);
	else if (test_duplicate_label(utils->label) == -1)
	{
		ft_putendl_fd(KRED"FATAL :Duplicate Label"KNRM, 2);
		fd = -1;
	}
	else
		print_output(utils, fd);
	ft_labeldel(&utils->label);
	ft_cmddel(&utils->cmds);
	ft_outputdel(&utils->output);
	if (fd != -1)
		close(fd);
	if (fd < 0)
		return (0);
	return (1);
}
