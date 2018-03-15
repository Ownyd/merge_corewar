/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:35:38 by tlux              #+#    #+#             */
/*   Updated: 2018/03/09 01:53:23 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static int		test_reg(char *reg, int opc, int index)
{
	if (ft_strlen(reg) > 2 || ft_atoi(reg) > REG_NUMBER || ft_atoi(reg) < 0)
		return (reg_error(1));
	if (opc == 1 || (opc == 2 && index == 0) || opc == 12 ||
			(opc == 13 && index == 0) || opc == 15 || opc == 9)
		return (reg_error(2));
	return (1);
}

static int		test_dir(char *dir, int opc, int index)
{
	int		i;
	char	*tmp;

	if ((i = 0) == 0 && ((opc == 2 && index == 1) || (opc == 3) || (opc == 4) ||
			(opc == 5) || (opc == 6 && index == 2) || (opc == 7 && index == 2)
			|| (opc == 8 && index == 2) || (opc == 10 && index == 2)
			|| (opc == 11 && index == 0) || (opc == 13 && index == 1)
			|| (opc == 14 && index == 2) || opc == 16))
		return (dir_error(1));
	if (dir[++i - 1] == ':')
	{
		while (ft_strchr(LABEL_CHARS, dir[i]) && dir[i] != '\0')
			i++;
		tmp = ft_strsub(dir, 1, i + 1);
		if (store_label(tmp, 0, 2) == -1)
		{
			free(tmp);
			return (dir_error(2));
		}
		free(tmp);
	}
	else if (!hexa_form(dir) && (!ft_isstrdigit(dir) || ft_atoll(dir) >
		0xFFFFFFFF || ft_atoll(dir) < -2147483648 || ft_strlen(dir) > 11))
		return (dir_error(3));
	return (1);
}

static int		test_indir(char *indir, int opc, int index)
{
	int		i;
	char	*tmp;

	if ((i = 0) == 0 && (opc == 1 || (opc == 2 && index == 1) || (opc == 3 &&
	index == 0) || opc == 4 || opc == 5 || (opc == 6 && index == 2) || (opc ==
	7 && index == 2) || (opc == 8 && index == 2) || opc == 9 || (opc == 10 &&
	index != 0) || (opc == 11 && index != 1) || opc == 12 || (opc == 13 &&
	index == 1) || (opc == 14 && index != 0) || opc == 15 || opc == 16))
		return (indir_error(1));
	if (indir[++i - 1] == ':')
	{
		while (ft_strchr(LABEL_CHARS, indir[i]) && indir[i] != '\0')
			i++;
		tmp = ft_strsub(indir, 1, i + 1);
		if (store_label(tmp, 0, 2) == -1)
		{
			free(tmp);
			return (indir_error(2));
		}
		free(tmp);
	}
	else if (!hexa_form(indir) && (!ft_isstrdigit(indir) || ft_strlen(indir) >
		11 || ft_atoll(indir) > 0xFFFFFFFF || ft_atoll(indir) < -2147483648))
		return (indir_error(3));
	return (1);
}

int				validity_params(int opc, char *params)
{
	char	**tmpt;
	int		i;

	i = -1;
	tmpt = ft_strsplit(params, ",");
	delspaces_tab(tmpt);
	while (++i < 3 && tmpt[i])
		if (tmpt[i][0] == 'r' && !test_reg(tmpt[i] + 1, opc, i))
			return (param_error(0, tmpt));
		else if (tmpt[i][0] == '%' && !test_dir(tmpt[i] + 1, opc, i))
			return (param_error(0, tmpt));
		else if (!ft_strchr("%r", tmpt[i][0]) && !test_indir(tmpt[i], opc, i))
			return (param_error(0, tmpt));
	if ((i == 3 && opc != 4 && opc != 5 && opc != 6 && opc != 7 && opc != 8
				&& opc != 10 && opc != 11 && opc != 14)
			|| (i == 2 && opc != 2 && opc != 3 && opc != 13)
			|| (i == 1 && opc != 1 && opc != 9 && opc != 12
				&& opc != 15 && opc != 16))
		return (param_error(1, tmpt));
	if ((i == 3 && tmpt[3] != NULL) || (i == 2 && tmpt[2] != NULL) ||
			(i == 1 && tmpt[1] != NULL) || (i == 0))
		return (param_error(2, tmpt));
	ft_tabfree(tmpt);
	return (1);
}
