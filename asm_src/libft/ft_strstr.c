/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:17:36 by tlux              #+#    #+#             */
/*   Updated: 2017/11/15 23:34:18 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int length;
	int count;

	length = -1;
	count = 0;
	if (*to_find == '\0')
		return ((char *)str);
	if (*str == '\0')
		return (0);
	while (to_find[length + 1] != 0)
		length++;
	while (*str != *to_find && *str != '\0')
		str++;
	while (count <= length)
	{
		if (*(str + count) != *(to_find + count) && *str != '\0')
			return (ft_strstr(str + 1, to_find));
		count++;
	}
	if (*str == '\0')
		return (0);
	return ((char *)str);
}
