/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:01:43 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 16:30:46 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	ft_labeldel(t_label **todel)
{
	t_label *cpy;
	t_label *tmp;

	cpy = *todel;
	while (cpy)
	{
		tmp = cpy->next;
		free(cpy->label);
		free(cpy);
		cpy = tmp;
	}
	*todel = NULL;
}
