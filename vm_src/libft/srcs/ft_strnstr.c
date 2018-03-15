/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:29:39 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/12 17:57:06 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_strinstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return (1);
	if (!len)
		return (0);
	if (!*haystack)
		return (0);
	if (*haystack == *needle && ft_strinstr(&haystack[1], &needle[1], len - 1))
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!len)
		return (NULL);
	if (!*needle)
		return ((char*)haystack);
	if (!*haystack)
		return (NULL);
	if (ft_strinstr(haystack, needle, len))
		return ((char*)haystack);
	return (ft_strnstr(&haystack[1], needle, len - 1));
}
