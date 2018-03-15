/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:21:42 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/10 12:31:45 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_readformat(char **str, t_formaitem format, va_list ap)
{
	char	*(*f)(va_list, t_formaitem*, int*);
	char	*ret;
	char	*tmp;
	int		size;

	size = 0;
	if (!(format.format = (*(*str)++)))
		(*str)--;
	f = ft_fonctformat(format.format, &format);
	if (!(ret = f(ap, &format, &size)))
		return (-1);
	if (size < format.min_size)
	{
		tmp = ft_strnew(format.min_size - size);
		ft_memset(tmp, (((format.flags & 512) && !(format.flags & 1024)) ?
					'0' : ' '), format.min_size - size);
		if (format.flags & 1024)
			ret = ft_strnjoin(ret, tmp, size, ft_strlen(tmp));
		else
			ret = ft_strnjoin(tmp, ret, ft_strlen(tmp), size);
		size = format.min_size;
	}
	write(1, ret, size);
	free(ret);
	return (size);
}

void	min_sizewildcard(t_formaitem *format, va_list ap, char **str)
{
	int ret;

	while (**str == '*' || ft_isdigit(**str))
	{
		if (**str == '*')
		{
			ret = va_arg(ap, int);
			if (ret < 0)
			{
				format->flags = format->flags | 1024;
				ret = -ret;
			}
			format->min_size = ret;
			(*str)++;
		}
		else
		{
			if (ft_isdigit(**str))
				format->min_size = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
}

void	precisionwildcard(t_formaitem *format, int ret)
{
	if (ret < 0)
		ret = -1;
	format->precision = ret;
}

int		ft_readflags(char **str, va_list ap)
{
	t_formaitem	format;
	int			tmp;

	format.precision = -1;
	format.min_size = 0;
	format.flags = 0;
	while ((tmp = ft_flag(str)))
		format.flags = format.flags | tmp;
	min_sizewildcard(&format, ap, str);
	if (**str == '.')
	{
		(*str)++;
		format.precision = ft_atoi(*str);
		if (**str == '*')
			precisionwildcard(&format, va_arg(ap, int));
		while (ft_isdigit(**str) || **str == '*')
			(*str)++;
	}
	format.flags = format.flags | ft_modifier(str);
	return (ft_readformat(str, format, ap));
}

int		ft_printf(char *format, ...)
{
	va_list ap;
	int		size;
	int		tmp;

	size = 0;
	va_start(ap, format);
	while (*format && !(*format == '%' && format[1] == 0))
	{
		if (*format != '%')
			size += ft_putstrfinalc(&format, '%');
		else
		{
			format++;
			tmp = ft_readflags(&format, ap);
			if (tmp == -1)
				return (-1);
			size += tmp;
		}
	}
	va_end(ap);
	return (size);
}
