/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:19:46 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 03:30:04 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <locale.h>

void	visu_init_color(void)
{
	start_color();
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_GUI_TITLE2, 300, 700, 1000);
	init_color(COLOR_GUI_TITLE3, 0, 1000, 500);
	init_pair(VOID_MEM, COLOR_VOID, COLOR_BLACK);
	init_pair(PROCESS_P1, COLOR_WHITE, COLOR_PROCESS1);
	init_pair(PROCESS_P2, COLOR_WHITE, COLOR_PROCESS2);
	init_pair(PROCESS_P3, COLOR_WHITE, COLOR_PROCESS3);
	init_pair(PROCESS_P4, COLOR_WHITE, COLOR_PROCESS4);
	init_pair(COLOR_P1, COLOR_PROCESS1, COLOR_BLACK);
	init_pair(COLOR_P2, COLOR_PROCESS2, COLOR_BLACK);
	init_pair(COLOR_P3, COLOR_PROCESS3, COLOR_BLACK);
	init_pair(COLOR_P4, COLOR_PROCESS4, COLOR_BLACK);
	init_pair(MEM, COLOR_YELLOW, COLOR_BLACK);
	init_pair(GUI_TITLE1, COLOR_WHITE, COLOR_BLACK);
	init_pair(GUI_TITLE2, COLOR_GUI_TITLE2, COLOR_BLACK);
	init_pair(GUI_TITLE3, COLOR_GUI_TITLE3, COLOR_BLACK);
	init_pair(GUI_CONTENT, COLOR_WHITE, COLOR_BLACK);
}

int		count_nb_process(t_process *process)
{
	int	ret;

	ret = 0;
	while (process)
	{
		process = process->next;
		ret++;
	}
	return (ret);
}

void	init_visu_ncurses(t_vm *vm)
{
	setlocale(LC_ALL, "");
	if (!(vm->visual = ft_memalloc(sizeof(t_visu))))
		exit(ft_er("malloc error\n"));
	initscr();
	noecho();
	curs_set(0);
	vm->visual->pause = 1;
	vm->visual->arena = subwin(stdscr, MEM_SIZE / 64 + 2, 64 * 3 + 1, 0, 0);
	vm->visual->gui = subwin(stdscr, MEM_SIZE / 64 + 2, 64, 0, 64 * 3);
	box(vm->visual->arena, ACS_VLINE, ACS_HLINE);
	box(vm->visual->gui, ACS_VLINE, ACS_HLINE);
	vm->visual->speed = 100;
	visu_init_color();
}

void	close_visu_ncurses(t_vm *vm)
{
	visu_print_winner(vm);
	while (getch() != 'q')
		;
	free(vm->visual);
	endwin();
}

void	visu_ncurses(t_vm *vm)
{
	visu_print_arena(vm);
	visu_print_gui(vm);
	sleep_visu(vm);
}
