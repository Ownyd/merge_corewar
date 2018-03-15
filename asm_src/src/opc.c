/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:32:00 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 19:22:21 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

long long	convert_neg(int toconv, int size)
{
	long long ret;

	ret = toconv;
	ret *= -1;
	if (size == 2)
		ret = (ret ^ 0xFFFF) + 1;
	else if (size == 4)
		ret = (ret ^ 0xFFFFFFFF) + 1;
	return (ret);
}

void		print_bits(int toprint, int size)
{
	long long ret;

	ret = toprint;
	if (toprint < 0)
		ret = convert_neg(toprint, size);
	if (size == 4)
	{
		store_output((int)((ret & 0xFF000000) >> 24), 1, 0);
		store_output((int)((ret & 0x00FF0000) >> 16), 1, 0);
	}
	store_output((int)((ret & 0x0000FF00) >> 8), 1, 0);
	store_output((int)((ret & 0x000000FF)), 1, 0);
}

void		print_dir(char *dir, int opc, int octet)
{
	int encode;
	int lbindex;

	encode = (opc == 1 || opc == 2 || opc == 6 || opc == 7 || opc == 8
			|| opc == 13) ? 4 : 2;
	if (dir[0] == ':')
	{
		lbindex = store_label(dir + 1, 0, 2);
		print_bits(lbindex - octet, encode);
	}
	else if (!hexa_form(dir))
		print_bits(ft_atoi(dir), encode);
	else
		print_bits(conv_hexa(dir + 2), encode);
}

void		print_indir(char *indir, int octet)
{
	int		i;
	char	*tmp;
	int		labcode;

	i = 0;
	if (indir[++i - 1] == ':')
	{
		while (ft_strchr(LABEL_CHARS, indir[i]) && indir[i] != '\0')
			i++;
		tmp = ft_strsub(indir, 1, i + 1);
		labcode = store_label(tmp, 0, 2);
		print_bits(labcode - octet, 2);
		free(tmp);
	}
	else if (!hexa_form(indir))
		print_bits(ft_atoi(indir), 2);
	else
		print_bits(conv_hexa(indir + 2), 2);
}

void		opc_params(char *params, int octet, int opc)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(params, ",");
	while (++i < 3 && tmp[i])
	{
		if (tmp[i][0] == 'r')
			store_output(ft_atoi(tmp[i] + 1), 1, 0);
		else if (tmp[i][0] == '%')
			print_dir(tmp[i] + 1, opc, octet);
		else
			print_indir(tmp[i], octet);
	}
	ft_tabfree(tmp);
}
