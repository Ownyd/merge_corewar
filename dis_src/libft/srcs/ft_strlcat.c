/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:51:53 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/15 15:01:16 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	ret = ((size < size_dst) ? size : size_dst);
	ret += ft_strlen(src);
	if (size - 1 > size_dst && size && *src)
	{
		dst[size_dst + 1] = 0;
		dst[size_dst] = *src;
		ft_strlcat(&dst[1], &src[1], size - 1);
	}
	return (ret);
}
