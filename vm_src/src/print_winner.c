/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:11:57 by emarin            #+#    #+#             */
/*   Updated: 2018/03/09 02:37:48 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_winner(t_vm *vm)
{
	t_player	*winner;
	int			i;
	int			num;

	num = vm->nb_player;
	winner = &vm->players[num - 1];
	i = -1;
	while (++i < vm->nb_player)
		if (vm->players[i].cycle_last_live > winner->cycle_last_live)
		{
			winner = &vm->players[i];
			num = i + 1;
		}
	ft_printf("le joueur %d(%s) a gagne\n", winner->num, winner->name);
}
