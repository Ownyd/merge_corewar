/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:53:52 by lowczarc          #+#    #+#             */
/*   Updated: 2018/02/15 18:32:39 by zerevo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreat(void *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->next = NULL;
	if (content == NULL)
	{
		ret->content_size = 0;
		ret->content = NULL;
		return (ret);
	}
	ret->content = content;
	ret->content_size = content_size;
	return (ret);
}
