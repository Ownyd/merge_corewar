/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:32:00 by tlux              #+#    #+#             */
/*   Updated: 2018/03/25 17:45:29 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static long long	convert_neg(int toconv, int size)
{
	long long ret;

	ret = toconv;
	ret *= -1;
	if (size == 2)
		ret = ((ret & 0x0000FFFF) ^ 0xFFFF) + 1;
	else if (size == 4)
		ret = ((ret & 0xFFFFFFFF) ^ 0xFFFFFFFF) + 1;
	return (ret);
}

void				print_bits(t_utils *utils, int toprint, int size)
{
	long long ret;

	ret = toprint;
	if (toprint < 0)
		ret = convert_neg(toprint, size);
	if (size == 4)
	{
		ft_outputadd(&(utils->output),
				ft_outputnew((int)((ret & 0xFF000000) >> 24)));
		ft_outputadd(&(utils->output),
				ft_outputnew((int)((ret & 0x00FF0000) >> 16)));
	}
	ft_outputadd(&(utils->output),
			ft_outputnew((int)((ret & 0x0000FF00) >> 8)));
	ft_outputadd(&(utils->output),
			ft_outputnew((int)((ret & 0x000000FF))));
}

static void			print_dir(char *dir, int opc, int octet, t_utils *utils)
{
	int encode;
	int lbindex;

	encode = (opc == 1 || opc == 2 || opc == 6 || opc == 7 || opc == 8
			|| opc == 13) ? 4 : 2;
	if (dir[0] == ':')
	{
		lbindex = return_label_pc(utils->label, dir + 1);
		print_bits(utils, lbindex - octet, encode);
	}
	else if (!hexa_form(dir))
		print_bits(utils, ft_atoi(dir), encode);
	else
		print_bits(utils, conv_hexa(dir + 2), encode);
}

static void			print_indir(char *indir, int octet, t_utils *utils)
{
	int		i;
	char	*tmp;
	int		labcode;

	i = 0;
	if (indir[++i - 1] == ':')
	{
		while (ft_strchr(LABEL_CHARS, indir[i]) && indir[i] != '\0')
			i++;
		if (!(tmp = ft_strsub(indir, 1, i)))
			malloc_error();
		labcode = return_label_pc(utils->label, tmp);
		print_bits(utils, labcode - octet, 2);
		free(tmp);
	}
	else if (!hexa_form(indir))
		print_bits(utils, ft_atoi(indir), 2);
	else
		print_bits(utils, conv_hexa(indir + 2), 2);
}

void				opc_params(char *params, int octet, int opc, t_utils *utils)
{
	char	**tmp;
	int		i;

	i = -1;
	if (!(tmp = ft_strsplit(params, ",")))
		malloc_error();
	while (++i < 3 && tmp[i])
	{
		if (tmp[i][0] == 'r')
			ft_outputadd(&(utils->output), ft_outputnew(ft_atoi(tmp[i] + 1)));
		else if (tmp[i][0] == '%')
			print_dir(tmp[i] + 1, opc, octet, utils);
		else
			print_indir(tmp[i], octet, utils);
	}
	ft_tabfree(tmp);
}
