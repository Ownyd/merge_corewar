/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:48:16 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 16:11:55 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include <stdio.h>

char	*signed_format(va_list ap, t_formaitem *format)
{
	if (format->flags & 4)
		return (ft_llitoa(va_arg(ap, long int), format));
	else if (format->flags & 1)
		return (ft_llitoa((char)va_arg(ap, int), format));
	else if (format->flags & 2)
		return (ft_llitoa((short)va_arg(ap, int), format));
	else if (format->flags & 8)
		return (ft_llitoa(va_arg(ap, long long int), format));
	else
		return (ft_llitoa(va_arg(ap, int), format));
}

char	*unsigned_format(va_list ap, t_formaitem *f)
{
	unsigned long long int	nb;

	if (f->flags & 4)
		nb = va_arg(ap, unsigned long);
	else if (f->flags & 1)
		nb = (unsigned char)va_arg(ap, int);
	else if (f->flags & 2)
		nb = (unsigned short)va_arg(ap, int);
	else if (f->flags & 8)
		nb = va_arg(ap, unsigned long long);
	else
		nb = va_arg(ap, unsigned int);
	if (f->format == 'x')
		return (ft_llxtoa(nb, f, "0123456789abcdef", "0x"));
	if (f->format == 'X')
		return (ft_llxtoa(nb, f, "0123456789ABCDEF", "0X"));
	if (f->format == 'o' || f->format == 'O')
		return (ft_llxtoa(nb, f, "01234567", "0"));
	if (f->format == 'b')
		return (ft_llxtoa(nb, f, "01", "0b"));
	return (ft_llutoa(nb, f->precision));
}

char	*int_format(va_list ap, t_formaitem *format, int *size)
{
	char		*ret;

	if (format->format == 'p')
		format->format = 'x';
	if (format->precision != -1 || format->flags & 1024)
		format->flags = format->flags & 0xFDFF;
	else if (format->precision == -1 && format->flags & 512)
		format->precision = format->min_size;
	ret = (format->flags & 64) ? unsigned_format(ap, format)
		: signed_format(ap, format);
	if (!(format->flags & 64) && ret[0] != '-')
	{
		if (format->flags & 2048)
			ret = ft_strfreejoin(ft_strdup("+"), ret);
		else if (format->flags & 4096)
			ret = ft_strfreejoin(ft_strdup(" "), ret);
	}
	*size = ft_strlen(ret);
	return (ret);
}
