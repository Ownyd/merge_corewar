/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/03/20 01:17:11 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

t_cmds	*ft_cmdnew(char *cmd, int opc)
{
	t_cmds *node;

	if (!(node = (t_cmds *)malloc(sizeof(*node))))
		return (0);
	node->cmd = ft_strdup(cmd);
	node->opc = opc;
	node->next = NULL;
	return (node);
}
