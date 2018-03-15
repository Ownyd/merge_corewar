/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_ncurses_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:36:13 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 04:00:13 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <locale.h>

void		color_on(t_vm *vm, int i, int size)
{
	if (vm->visual->arena_color[i])
		wattron(vm->visual->arena,
				COLOR_PAIR((COLOR_P1 - 1) + vm->visual->arena_color[i]));
	else
		wattron(vm->visual->arena, COLOR_PAIR(VOID_MEM));
	if (size > 0)
		wattron(vm->visual->arena, A_BOLD);
}

void		color_off(t_vm *vm, int *size, t_process *is_proc)
{
	wattroff(vm->visual->arena, COLOR_PAIR(VOID_MEM));
	if (--(*size) == 0)
		wattroff(vm->visual->arena, A_BOLD);
	if (is_proc)
		wattroff(vm->visual->arena, COLOR_PAIR(PROCESS_P1 + is_proc->player));
}

void		visu_print_arena(t_vm *vm)
{
	int			i;
	t_process	*is_proc;
	int			size;

	i = -1;
	size = -1;
	while (++i < MEM_SIZE)
	{
		is_proc = get_last_process_at_pc(vm, i);
		color_on(vm, i, size);
		if (is_proc)
		{
			if (is_proc->instr)
				size = size_instr(is_proc->instr[0],
					&vm->arena[(is_proc->pc + 1) % MEM_SIZE]);
			wattron(vm->visual->arena,
					COLOR_PAIR(PROCESS_P1 + is_proc->player));
		}
		mvwprintw(vm->visual->arena, (i / 64) + 1, (i % 64) * 3 + 1,
				"%.2hhx", vm->arena[i]);
		color_off(vm, &size, is_proc);
	}
	if (size > 0)
		wattroff(vm->visual->arena, A_BOLD);
	wrefresh(vm->visual->arena);
}

void		visu_print_gui(t_vm *vm)
{
	int	i;

	i = -1;
	print_title(vm);
	wattron(vm->visual->gui, COLOR_PAIR(GUI_CONTENT));
	while (++i < vm->nb_player)
		print_player(vm, &(vm->players[i]), i);
	mvwprintw(vm->visual->gui, 6 + (3 * i), 2, "Cycles : % 6d", vm->cycle);
	if (vm->visual->speed <= 200)
		mvwprintw(vm->visual->gui, 8 + (3 * i), 2, "Speed : % 6d%% ",
				vm->visual->speed);
	else
		mvwprintw(vm->visual->gui, 8 + (3 * i), 2, "Speed :     Max.");
	mvwprintw(vm->visual->gui, 12 + (3 * i), 26,
			(vm->visual->pause) ? "| PAUSE |" : "         ");
	mvwprintw(vm->visual->gui, 10 + (3 * i), 2,
			"Process : %5d", count_nb_process(vm->process));
	mvwprintw(vm->visual->gui, 15 + (3 * i), 2, "CYCLE_TO_DIE : %d",
			vm->cycle_to_die);
	mvwprintw(vm->visual->gui, 17 + (3 * i), 2, "CYCLE_DELTA : %d",
			CYCLE_DELTA);
	mvwprintw(vm->visual->gui, 19 + (3 * i), 2, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(vm->visual->gui, 21 + (3 * i), 2, "MAX_CHECKS : %d", MAX_CHECKS);
	wrefresh(vm->visual->gui);
}

void		visu_print_winner(t_vm *vm)
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
	wattron(vm->visual->gui, A_BOLD);
	mvwprintw(vm->visual->gui, 25 + (3 * i), 24, "# Victoire #");
	wattron(vm->visual->gui, COLOR_PAIR(COLOR_P1 + i - 1));
	mvwprintw(vm->visual->gui, 27 + (3 * i),
			30 - (ft_strlen_unicode(winner->name) / 2), winner->name);
	wattroff(vm->visual->gui, A_BOLD | COLOR_PAIR(COLOR_P1 + i - 1));
	wrefresh(vm->visual->gui);
}
