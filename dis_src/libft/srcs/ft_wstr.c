/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:47:39 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 11:47:10 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

static unsigned int		nbrchars(wchar_t c)
{
	unsigned int	ret;

	ret = 0;
	if (c < 128)
		return (1);
	while (c != 0)
	{
		ret++;
		c = (c >> 1) & 0x7FFFFFFF;
	}
	ret = ((ret - 2) / 5) + 1;
	if (ret > (unsigned int)MB_CUR_MAX)
		return (-1);
	return (ret);
}

static char				firstbyte(int size, char c)
{
	char	ret;

	ret = 0;
	while (size--)
		ret = (ret >> 1) | 0x80;
	return (ret | c);
}

char					*wchar_to_str(wchar_t c)
{
	char	*ret;
	int		i;
	int		size;

	i = nbrchars(c);
	if ((size = i) == -1)
		return (NULL);
	ret = ft_memalloc(i + sizeof(char));
	if (c < 128)
	{
		ret[0] = c;
		return (ret);
	}
	while (i--)
	{
		if (i)
		{
			ret[i] = (c & 0x3F) | 0x80;
			c = (c >> 6) & 0x3FFFFFF;
		}
		else
			ret[i] = firstbyte(size, c);
	}
	return (ret);
}

char					*wstr_to_str(wchar_t *str, int size)
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	ret = ft_strdup("");
	while (str[i] && ft_strlen(ret) < (size_t)size)
	{
		if (!wchar_to_str(str[i]))
		{
			free(ret);
			return ((void*)-1);
		}
		if (ft_strlen(ret) + ft_strlen(wchar_to_str(str[i])) <= (size_t)size)
			ret = ft_strfreejoin(ret, wchar_to_str(str[i]));
		i++;
	}
	return (ret);
}

size_t					ft_wstrlen(wchar_t *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
