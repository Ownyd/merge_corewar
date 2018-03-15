/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:09:43 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/08 11:26:55 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*m;

	i = 0;
	while (i < (int)len)
	{
		m = (unsigned char *)(b + i);
		*m = (unsigned char)c;
		i++;
	}
	return (b);
}
