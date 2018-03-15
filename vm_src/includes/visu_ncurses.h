/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_ncurses.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:01:07 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/15 16:04:04 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_NCURSES_H
# define VISU_NCURSES_H

# include <ncurses.h>
# define COLOR_PROCESS1 2
# define COLOR_PROCESS2 4
# define COLOR_PROCESS3 3
# define COLOR_PROCESS4 5
# define COLOR_VOID 8
# define COLOR_INSTR 3
# define COLOR_GUI_TITLE2 65
# define COLOR_GUI_TITLE3 66
# define COLOR_TRUE 67
# define COLOR_FALSE 68
# define VOID_MEM 1
# define PROCESS_P1 2
# define PROCESS_P2 3
# define PROCESS_P3 4
# define PROCESS_P4 5
# define TRUE_INSTR 6
# define FALSE_INSTR 7
# define MEM 8
# define COLOR_P1 9
# define COLOR_P2 10
# define COLOR_P3 11
# define COLOR_P4 12
# define GUI_TITLE1 13
# define GUI_TITLE2 14
# define GUI_TITLE3 15
# define GUI_CONTENT 16

typedef	struct	s_visu
{
	int		speed;
	int		pause;
	char	arena_color[MEM_SIZE];
	WINDOW	*arena;
	WINDOW	*gui;
}				t_visu;

#endif
