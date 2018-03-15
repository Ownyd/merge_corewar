/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:56 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:40:42 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	ft_labeladd(t_label **alst, t_label *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
