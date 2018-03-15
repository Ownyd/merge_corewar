/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:55:33 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/10 13:08:29 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strinstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return (1);
	if (!*haystack)
		return (0);
	if (*haystack == *needle && ft_strinstr(&haystack[1], &needle[1]))
		return (1);
	return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return ((char*)haystack);
	if (!*haystack)
		return (NULL);
	if (ft_strinstr(haystack, needle))
		return ((char*)haystack);
	return (ft_strstr(&haystack[1], needle));
}
