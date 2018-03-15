/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:31:06 by tlux              #+#    #+#             */
/*   Updated: 2018/03/09 02:20:53 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

static int	test_duplicate(t_label *lbs)
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

int			store_label(char *label, int octet, int cmd)
{
	static t_label	*lbs = NULL;
	t_label			*tmp;

	tmp = lbs;
	if (cmd == 1)
		ft_labeladd(&lbs, ft_labelnew(label, octet));
	if (cmd == 2)
		while (tmp)
		{
			if (ft_strcmp(tmp->label, label) == 0)
				return (tmp->octet);
			tmp = tmp->next;
		}
	if (cmd == 3)
		ft_labeldel(&lbs);
	if (cmd == 4)
		return (test_duplicate(lbs));
	return (-1);
}
