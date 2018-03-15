/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:57:05 by emarin            #+#    #+#             */
/*   Updated: 2018/03/15 16:28:28 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

char	init_disassembler(char **argv, t_player *player)
{
	int	fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_er("open error\n"));
	if (!store_prog(fd, argv[1], player))
		return (0);
	if (close(fd) == -1)
		return (ft_er("close error\n"));
	return (1);
}

void	print_arg(t_player *player, int *i, t_op *operateur)
{
	int		j;
	char	arg;

	arg = player->prog[(*i)++];
	j = -1;
	while (++j < 4 && (((arg >> (6 - 2 * j)) & 3) == REG_CODE
	|| ((arg >> (6 - 2 * j)) & 3) == DIR_CODE
	|| ((arg >> (6 - 2 * j)) & 3) == IND_CODE))
	{
		if (j > 0)
			ft_putstr(",");
		if (((arg >> (6 - 2 * j)) & 3) == REG_CODE)
			ft_printf("r%lld", par_to_ll(&(player->prog[(*i)++]), 1));
		else if (((arg >> (6 - 2 * j)) & 3) == DIR_CODE)
		{
			ft_printf("%%%lld", par_to_ll(&(player->prog[*i])
			, 4 - (2 * operateur->dir_size)));
			*i += 4 - (2 * operateur->dir_size);
		}
		else if (((arg >> (6 - 2 * j)) & 3) == IND_CODE)
		{
			ft_printf("%lld", par_to_ll(&(player->prog[*i]), IND_SIZE));
			*i += IND_SIZE;
		}
	}
}

void	print_arg_no_ocp(t_player *player, int *i, t_op *operateur)
{
	ft_printf("%%%lld", par_to_ll(&(player->prog[*i])
	, 4 - (2 * operateur->dir_size)));
	*i += 4 - (2 * operateur->dir_size);
}


void	disassembler(t_player *player)
{
	t_op	*operateur;
	int		i;

	ft_printf(".name \"%s\"\n", player->name);
	ft_printf(".comment \"%s\"\n\n", player->comment);
	i = 0;
	while (i < player->prog_size)
	{
		if ((operateur = get_op_by_id(player->prog[i])))
		{
			++i;
			ft_printf("%s\t", operateur->name);
			if (operateur->ocp)
				print_arg(player, &i, operateur);
			else
				print_arg_no_ocp(player, &i, operateur);
			ft_printf("\n");
		}
		else
			++i;
	}
}

int		main(int argc, char **argv)
{
	t_player	player;

	if (argc != 2)
		return (usage_disassembler());
	if (!(init_disassembler(argv, &player)))
		return (1);
	disassembler(&player);
	free(player.prog);
	return (0);
}
