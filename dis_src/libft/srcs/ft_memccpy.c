/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:45:41 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/14 19:48:40 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!n)
		return (NULL);
	while (n && *((char*)src) != (char)c)
	{
		*((char*)dst) = *((char*)src);
		dst++;
		src++;
		n--;
	}
	if (n && *((char*)src) == (char)c)
	{
		*((char*)dst) = *((char*)src);
		dst++;
		return (dst);
	}
	return (NULL);
}
