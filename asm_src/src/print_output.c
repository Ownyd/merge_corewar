/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:48:23 by tlux              #+#    #+#             */
/*   Updated: 2018/03/17 00:55:33 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	print_output(t_utils *utils, int fd)
{
	t_otp *tmp;

	tmp = utils->output;
	while (tmp)
	{
		ft_putchar_fd(tmp->c, fd);
		tmp = tmp->next;
	}
}
