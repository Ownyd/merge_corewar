/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 02:25:30 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 18:21:06 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static void		test_av(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (i <= 2 || av[i - 1] != 's' || av[i - 2] != '.')
	{
		ft_putendl_fd("This is not a corewar file", 2);
		exit(1);
	}
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
	tmp = ft_strjoin(av, "cor");
	if ((fd = open(tmp, O_CREAT | O_RDWR, 0755)) != -1)
	{
		ft_putstr("Writing output program to ");
		ft_putendl(tmp);
	}
	free(tmp);
	return (fd);
}

int				init_utils(int ac, char **av)
{
	int fd;

	test_av(av[ac - 1]);
	fd = open(av[ac - 1], O_RDONLY);
	if (ac == 1)
	{
		ft_putendl_fd("No file inputed", 2);
		exit(1);
	}
	if (fd < 0)
	{
		ft_putendl_fd("The file doesn't exist", 2);
		exit(1);
	}
	commandlist(NULL, 0);
	get_fd(1, fd);
	return (fd);
}

int				end_utils(int ac, char **av)
{
	int fd;

	fd = -1;
	if (store_label(NULL, 0, 4) == -1)
		ft_putendl_fd("Duplicate Label", 2);
	else if ((fd = create_file(av[ac - 1])) < 0)
		ft_putendl_fd("Error during creation of the .cor file", 2);
	else
		store_output(0, 2, fd);
	store_label(NULL, 0, 3);
	commandlist(NULL, 2);
	store_output(0, 3, 0);
	if (fd != -1)
		close(fd);
	return (0);
}
