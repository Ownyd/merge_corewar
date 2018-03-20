/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/03/17 00:47:25 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

t_otp	*ft_outputnew(int opc)
{
	t_otp *node;

	if (!(node = (t_otp *)malloc(sizeof(*node))))
		return (NULL);
	node->c = (char)opc;
	node->next = NULL;
	return (node);
}
