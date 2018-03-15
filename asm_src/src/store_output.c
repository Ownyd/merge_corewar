/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:48:23 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:30:32 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	store_output(int c, int cmd, int fd)
{
	static t_otp	*output = NULL;
	t_otp			*tmp;

	tmp = output;
	if (cmd == 1)
		ft_outputadd(&output, ft_outputnew(c));
	else if (cmd == 2)
		while (tmp)
		{
			ft_putchar_fd(tmp->c, fd);
			tmp = tmp->next;
		}
	else if (cmd == 3)
		ft_outputdel(&output);
}
