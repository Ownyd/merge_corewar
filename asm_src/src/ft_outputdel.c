/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:01:43 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 16:29:14 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	ft_outputdel(t_otp **todel)
{
	t_otp	*cpy;
	t_otp	*tmp;

	cpy = *todel;
	while (cpy)
	{
		tmp = cpy->next;
		free(cpy);
		cpy = tmp;
	}
	*todel = NULL;
}
