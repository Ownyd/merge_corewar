/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:54:24 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/08 11:52:48 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char	*char_format(va_list ap, t_formaitem *format, int *size)
{
	char *ret;

	if (!(format->flags & 4))
	{
		ret = ft_memalloc(2);
		ret[0] = va_arg(ap, int);
	}
	else
		ret = wchar_to_str(va_arg(ap, wchar_t));
	if (!ret)
		return (NULL);
	*size = (!ft_strlen(ret)) ? 1 : ft_strlen(ret);
	return (ret);
}
