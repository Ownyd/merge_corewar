/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:01:39 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/16 18:05:01 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **alst, int (*cmp)(void*, void*, void*), void *param)
{
	t_list	**list;
	t_list	*tmp;

	list = alst;
	while (*list && (*list)->next)
	{
		if (cmp((*list)->content, (*list)->next->content, param))
			list = &((*list)->next);
		else
		{
			tmp = *list;
			*list = (*list)->next;
			tmp->next = (*list)->next;
			(*list)->next = tmp;
			list = alst;
		}
	}
}
