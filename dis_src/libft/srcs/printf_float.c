/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:34:06 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 18:53:59 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

static char	*spaghetti(unsigned long long j, char *ret, int size,
		t_formaitem *format)
{
	while (j != 0)
	{
		if (!size)
			ret = ft_strfreejoin(ft_strdup("."), ret);
		ret = ft_strfreejoin(ft_llitoa(j % 10, format), ret);
		j /= 10;
		size--;
	}
	return (ret);
}

char		*ft_floatoa(double f, t_formaitem *format)
{
	int						size;
	char					*ret;
	int						i;
	int						neg;
	unsigned long long		j;

	i = 0;
	size = (format->precision == -1) ? 6 : format->precision;
	format->precision = -1;
	ret = ft_strdup("");
	neg = f < 0;
	f = (neg) ? -f : f;
	j = (long long)f;
	while (size - (i++))
	{
		f = (f - (long long)f) * 10;
		j = j * 10 + (long long)f;
	}
	ret = spaghetti(j + ((f - (long long)f > 0.5) ? 1 : 0), ret, size, format);
	if (neg)
		ret = ft_strfreejoin(ft_strdup("-"), ret);
	return (ret);
}

char		*float_format(va_list ap, t_formaitem *format, int *size)
{
	char		*ret;
	double		f;

	f = va_arg(ap, double);
	if (f != f)
		ret = ft_strdup((format->flags & 4) ? "NAN" : "nan");
	else if (f == INFINITY)
	{
		ret = ft_strdup((format->flags & 4) ? "INF" : "inf");
	}
	else
	{
		ret = ft_floatoa(f, format);
		if (ret[0] != '-')
		{
			if (format->flags & 2048)
				ret = ft_strfreejoin(ft_strdup("+"), ret);
			else if (format->flags & 4096)
				ret = ft_strfreejoin(ft_strdup(" "), ret);
		}
	}
	*size = ft_strlen(ret);
	return (ret);
}
