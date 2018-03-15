/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:57:05 by emarin            #+#    #+#             */
/*   Updated: 2018/03/09 00:16:08 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				count_nb_player(int argc, char **argv, t_vm *vm)
{
	int	i;

	vm->nb_player = 0;
	i = 0;
	while (++i < argc)
		if (!ft_strcmp(argv[i], "-dump"))
		{
			if (!(++i < argc && ft_isnumber(argv[i]) && ft_overflow(argv[i])))
				return (usage(0));
		}
		else if (!ft_strcmp(argv[i], "-n"))
		{
			if (!(++i < argc && (ft_isnumber(argv[i])
							|| (argv[i][0] && ft_isnumber(&argv[i][1])))))
				return (usage(0));
		}
		else if (ft_strcmp(argv[i], "-Vncurses"))
			++(vm->nb_player);
	if (vm->nb_player == 0)
		return (usage(0));
	if (vm->nb_player > MAX_PLAYERS)
		return (ft_er("Trop de champions !\n"));
	return (1);
}

void			set_player_nb_par(t_vm *vm, long long new_player_nb, int play_i
, char *player_nb)
{
	if (new_player_nb < 1LL << (8 * REG_SIZE))
	{
		if (player_nb_exist(vm, player_nb, new_player_nb))
			ft_printf("Warning:\n\t\"-n %lld"
			"\" ignored, because the number is already set\n", new_player_nb);
		else
		{
			player_nb[play_i] = 1;
			vm->players[play_i].num = new_player_nb;
		}
	}
	else
		ft_printf("Warning:\n\t\"-n %lld"
		"\" ignored, because it's bigger than registery\n", new_player_nb);
}

char			arg_parse(int argc, char **argv, t_vm *vm)
{
	int			i;
	int			play_i;
	char		player_nb[MAX_PLAYERS];
	char		is_new_player_nb;
	long long	new_player_nb;

	if (!count_nb_player(argc, argv, vm))
		return (0);
	if (!(vm->players = (t_player*)malloc(sizeof(t_player) * vm->nb_player)))
		return (ft_er("malloc error\n"));
	is_new_player_nb = 0;
	ft_bzero(player_nb, MAX_PLAYERS);
	i = 0;
	play_i = -1;
	while (++i < argc)
		if (!ft_strcmp(argv[i], "-Vncurses"))
			vm->visu = 1;
		else if (!ft_strcmp(argv[i], "-dump") && ++i)
			vm->dump_nbr_cycles = ft_atoi(argv[i]);
		else if (!ft_strcmp(argv[i], "-n") && ++i && (is_new_player_nb = 1))
			new_player_nb = ft_atoi_l(argv[i]);
		else if (++play_i >= 0 && is_new_player_nb && !(is_new_player_nb = 0))
			set_player_nb_par(vm, new_player_nb, play_i, player_nb);
	set_player_nb(vm, player_nb);
	return (1);
}

char			store_progs(int argc, char **argv, t_vm *vm)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-n")
				|| (!ft_strcmp(argv[i], "-Vncurses") && i--))
			++i;
		else
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				return (ft_er("open error\n"));
			if (!store_prog(fd, argv[i], &(vm->players[j])))
				return (0);
			j++;
			if (close(fd) == -1)
				return (ft_er("close error\n"));
		}
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_vm	vm;

	if (argc == 1)
		return (usage(1));
	if (!init_vm(&vm))
		return (close_vm(&vm, 1));
	if (!arg_parse(argc, argv, &vm))
		return (close_vm(&vm, 1));
	if (!store_progs(argc, argv, &vm))
		return (close_vm(&vm, 1));
	if (vm.visu == 1)
		init_visu_ncurses(&vm);
	charge_memory(&vm);
	if (!(loop_vm(&vm)))
		return (close_vm(&vm, 1));
	if (vm.visu == 1)
		close_visu_ncurses(&vm);
	else
		print_winner(&vm);
	return (close_vm(&vm, 0));
}
