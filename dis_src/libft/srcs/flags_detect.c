/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_detect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:16:20 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/07 17:45:07 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_flags		g_modifier[] =
{
	{"hh", 1},
	{"h", 2},
	{"ll", 8},
	{"l", 4},
	{"j", 8},
	{"z", 4},
	{NULL, 0}
};

const t_flags		g_flag[] =
{
	{"#", 256},
	{"0", 512},
	{"-", 1024},
	{"+", 2048},
	{" ", 4096},
	{NULL, 0}
};

const t_format	g_format[] =
{
	{'s', &string_format, 0},
	{'S', &string_format, 4},
	{'p', &int_format, 452},
	{'d', &int_format, 0},
	{'D', &int_format, 4},
	{'i', &int_format, 0},
	{'o', &int_format, 96},
	{'O', &int_format, 100},
	{'u', &int_format, 64},
	{'U', &int_format, 68},
	{'x', &int_format, 64},
	{'X', &int_format, 64},
	{'b', &int_format, 64},
	{'f', &float_format, 0},
	{'F', &float_format, 4},
	{'c', &char_format, 0},
	{'C', &char_format, 4},
	{0, &pourcent_format, 0}
};

int		ft_modifier(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (g_modifier[i].str)
	{
		j = 0;
		while (g_modifier[i].str[j] && g_modifier[i].str[j] == (*str)[j])
			j++;
		if (!g_modifier[i].str[j])
		{
			*str = &(*str)[j];
			return (g_modifier[i].flag);
		}
		i++;
	}
	return (0);
}

int		ft_flag(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (g_flag[i].str)
	{
		j = 0;
		while (g_flag[i].str[j] && g_flag[i].str[j] == (*str)[j])
			j++;
		if (!g_flag[i].str[j])
		{
			*str = &(*str)[j];
			return (g_flag[i].flag);
		}
		i++;
	}
	return (0);
}

int		ft_isformat(char c)
{
	int	i;

	i = 0;
	while (g_format[i].c)
	{
		if (g_format[i].c == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_fonctformat(char c, t_formaitem *format)
{
	int	i;

	i = 0;
	while (g_format[i].c)
	{
		if (g_format[i].c == c)
		{
			format->flags = format->flags | g_format[i].flag;
			return (g_format[i].fonct);
		}
		i++;
	}
	return (g_format[i].fonct);
}
