/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 08:04:23 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/16 16:01:17 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
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
	ret->content = malloc(content_size);
	ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	return (ret);
}
