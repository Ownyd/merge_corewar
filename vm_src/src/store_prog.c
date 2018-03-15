/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:56:44 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/08 19:35:36 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	rev_int(int ret)
{
	int b[4];

	b[0] = (ret >> 24) & 0xFF;
	b[1] = (ret >> 16) & 0xFF;
	b[2] = (ret >> 8) & 0xFF;
	b[3] = ret & 0xFF;
	return (b[0] | (b[1] * 0x100) | (b[2] * 0x10000) | (b[3] * 0x1000000));
}

int	check_magic(int fd)
{
	int magic;

	if (read(fd, &magic, 4) != 4)
		return (0);
	magic = rev_int(magic);
	if (magic != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

int	get_prog_name(int fd, t_player *player)
{
	if (read(fd, player->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		return (0);
	return (1);
}

int	store_prog(int fd, char *name, t_player *player)
{
	int	unused;

	if (!check_magic(fd)
			|| read(fd, player->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH
			|| read(fd, &unused, 4) != 4
			|| read(fd, &(player->prog_size), 4) != 4
			|| read(fd, player->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
	{
		ft_printf("%s is not a corewar executable\n", name);
		return (0);
	}
	if ((player->prog_size = rev_int(player->prog_size)) > CHAMP_MAX_SIZE)
		ft_printf("%s is too large (%d bytes > %d bytes)\n", name,
				player->prog_size, CHAMP_MAX_SIZE);
	if (player->prog_size > CHAMP_MAX_SIZE)
		return (0);
	if (!(player->prog = malloc(player->prog_size)))
		return (ft_er("Can't perform malloc\n"));
	if (read(fd, &unused, 4) != 4 || read(fd, player->prog, player->prog_size)
	!= player->prog_size || read(fd, &unused, 4) != 0)
	{
		ft_printf("%s is not a corewar executable\n", name);
		return (0);
	}
	return (1);
}
