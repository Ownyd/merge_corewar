/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:50:07 by tlux              #+#    #+#             */
/*   Updated: 2017/11/13 20:12:38 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *calst;

	calst = *alst;
	while (calst)
	{
		del((calst)->content, (calst)->content_size);
		free(calst);
		calst = calst->next;
	}
	*alst = NULL;
}
