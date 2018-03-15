/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:01:43 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:40:48 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	ft_labeldel(t_label **todel)
{
	t_label *cpy;

	cpy = *todel;
	while (cpy)
	{
		free(cpy->label);
		free(cpy);
		cpy = cpy->next;
	}
	*todel = NULL;
}
