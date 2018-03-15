/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:52:30 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/07 19:00:21 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_llutoa(unsigned long long int n)
{
	unsigned long long int	ret;

	ret = 0;
	while (n >= 10)
	{
		ret++;
		n /= 10;
	}
	ret++;
	return (ret);
}

static void	ft_putinstr(char *s, unsigned long long n, int size)
{
	while (size > 0)
	{
		size--;
		s[size] = (n % 10) + '0';
		n = n / 10;
	}
}

char		*ft_llutoa(unsigned long long int n, int size)
{
	char	*ret;

	if (size < size_llutoa(n) && !(n == 0 && size == 0))
		size = size_llutoa(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ft_putinstr(ret, n, size);
	ret[size] = 0;
	return (ret);
}

char		*ft_llitoa(long long int n, t_formaitem *format)
{
	char	*tmp;
	char	*ret;
	int		size;

	size = format->precision - 1
		+ (!(format->flags & 512) && format->precision != -1);
	tmp = ft_llutoa((n < 0) ? -n : n, size);
	ret = (n < 0) ? ft_strfreejoin(ft_strdup("-"), tmp) : tmp;
	return (ret);
}
