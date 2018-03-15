/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2017/11/13 20:15:08 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(*node));
	if (node == NULL)
		return (0);
	if (!content)
	{
		node->content_size = 0;
		node->content = NULL;
	}
	else
	{
		if ((node->content = malloc(content_size)) == NULL)
		{
			free(node);
			return (0);
		}
		node->content_size = content_size;
		ft_memcpy(node->content, content, content_size);
	}
	node->next = NULL;
	return (node);
}
