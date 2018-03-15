/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:40:03 by emarin            #+#    #+#             */
/*   Updated: 2018/03/15 17:52:22 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

int		usage_disassembler(void)
{
	ft_putstr("usage:\n./disassembler champion.cor\n");
	return (1);
}

int		ft_er(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (0);
}
