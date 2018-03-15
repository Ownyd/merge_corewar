/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:06:29 by tlux              #+#    #+#             */
/*   Updated: 2018/01/25 05:49:15 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_contdel(void *content, size_t content_size)
{
	if (content_size)
	{
		free(content);
		content = NULL;
		content_size = 0;
	}
}
