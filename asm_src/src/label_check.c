/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:31:06 by tlux              #+#    #+#             */
/*   Updated: 2018/03/18 19:19:30 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int			test_duplicate_label(t_label *lbs)
{
	t_label	*act;
	t_label	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	act = lbs;
	while (act)
	{
		tmp = lbs;
		while (tmp)
		{
			if (ft_strcmp(tmp->label, act->label) == 0 && i != j)
			{
				return (-1);
			}
			tmp = tmp->next;
			j++;
		}
		j = 0;
		i++;
		act = act->next;
	}
	return (1);
}

int			return_label_pc(t_label *lbs, char *label)
{
	t_label	*tmp;

	tmp = lbs;
	while (tmp)
	{
		if (ft_strcmp(tmp->label, label) == 0)
			return (tmp->octet);
		tmp = tmp->next;
	}
	return (-1);
}
