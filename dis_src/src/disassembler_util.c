/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:40:03 by emarin            #+#    #+#             */
/*   Updated: 2018/03/15 16:23:52 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

int		usage_disassembler()
{
	ft_putstr("usage:\n./disassembler champion.cor\n");
	return (1);
}

int		ft_er(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (0);
}
