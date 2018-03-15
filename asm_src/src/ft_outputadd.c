/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:56 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:41:01 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

void	ft_outputadd(t_otp **alst, t_otp *new)
{
	t_otp *calst;

	calst = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (calst->next)
	{
		calst = calst->next;
	}
	calst->next = new;
}
