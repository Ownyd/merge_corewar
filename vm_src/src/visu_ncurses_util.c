/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_ncurses_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:59:32 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/09 03:29:51 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*get_last_process_at_pc(t_vm *vm, int pc)
{
	t_process	*ret;

	ret = vm->process;
	while (ret)
	{
		if (ret->pc == pc)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}

void		print_title(t_vm *vm)
{
	wattron(vm->visual->gui, A_BOLD | COLOR_PAIR(GUI_TITLE1));
	mvwprintw(vm->visual->gui, 2, 27, "C");
	wattroff(vm->visual->gui, COLOR_PAIR(GUI_TITLE1));
	wattron(vm->visual->gui, A_DIM | COLOR_PAIR(GUI_TITLE2));
	wprintw(vm->visual->gui, "O");
	wattroff(vm->visual->gui, A_DIM | COLOR_PAIR(GUI_TITLE2));
	wattron(vm->visual->gui, COLOR_PAIR(GUI_TITLE1));
	wprintw(vm->visual->gui, "REW");
	wattroff(vm->visual->gui, COLOR_PAIR(GUI_TITLE1));
	wattron(vm->visual->gui, A_DIM | COLOR_PAIR(GUI_TITLE3));
	wprintw(vm->visual->gui, "%C", L'Δ');
	wattroff(vm->visual->gui, A_DIM | COLOR_PAIR(GUI_TITLE3));
	wattron(vm->visual->gui, COLOR_PAIR(GUI_TITLE1));
	wprintw(vm->visual->gui, "R");
	wattroff(vm->visual->gui, A_BOLD | COLOR_PAIR(GUI_TITLE1));
}

void		print_player(t_vm *vm, t_player *player, int i)
{
	mvwprintw(vm->visual->gui, 5 + (3 * i), 2, "Player %d : ", player->num);
	wattron(vm->visual->gui, A_BOLD | COLOR_PAIR(COLOR_P1 + i));
	wprintw(vm->visual->gui, player->name);
	mvwprintw(vm->visual->gui, 6 + (3 * i), 6,
			"Lives : % 6d", player->nb_lives);
	wattroff(vm->visual->gui, A_BOLD | COLOR_PAIR(COLOR_P1 + i));
}

char		keyboard_visu(t_vm *vm)
{
	char	c;

	nodelay(stdscr, 1);
	c = getch();
	if (c == '+')
		vm->visual->speed += (vm->visual->speed > 200) ? 0 : 1;
	else if (c == '-')
		vm->visual->speed -= (vm->visual->speed <= 1) ? 0 : 1;
	else if (c == ' ')
		vm->visual->pause = !vm->visual->pause;
	else if (c == 'q')
	{
		free(vm->visual);
		endwin();
		exit(0);
	}
	nodelay(stdscr, 0);
	return (c);
}

void		sleep_visu(t_vm *vm)
{
	int	i;

	i = 0;
	while (i <= 200 / vm->visual->speed)
	{
		keyboard_visu(vm);
		visu_print_gui(vm);
		if (vm->visual->speed <= 200)
			usleep(10000);
		i++;
	}
	while (vm->visual->pause)
	{
		visu_print_gui(vm);
		if (keyboard_visu(vm) == 's')
			break ;
	}
}
