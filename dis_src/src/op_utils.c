/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:46:44 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/15 16:22:59 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

long long	par_to_ll(char *param, int par_size)
{
	long long	res;
	int			neg;
	int			i;

	res = 0;
	i = 0;
	neg = ((param[0] & 0x80) == 0x80);
	while (i < par_size)
	{
		res = res << 8;
		res = (neg) ? res | (~param[i] & 0xFF) : res | (param[i] & 0xFF);
		++i;
	}
	if (neg)
		res = (res + 1) * -1;
	return (res);
}

t_op		*get_op_by_id(unsigned char index)
{
	int	i;

	i = 0;
	while (g_op[i].index != index && g_op[i].index != 0)
	{
		i++;
	}
	if (g_op[i].index == 0)
		return (NULL);
	return ((t_op*)&g_op[i]);
}
