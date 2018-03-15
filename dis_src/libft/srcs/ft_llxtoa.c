/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:37:17 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 11:46:00 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_llxtoa(unsigned long long int n, char *base)
{
	unsigned long long int	ret;

	ret = 0;
	while (n >= ft_strlen(base))
	{
		ret++;
		n /= ft_strlen(base);
	}
	ret++;
	return (ret);
}

static void	ft_putinstr(char *s, unsigned long long n, int size, char *base)
{
	while (size > 0)
	{
		size--;
		s[size] = base[(n % ft_strlen(base))];
		n = n / ft_strlen(base);
	}
}

char		*ft_llxtoa(unsigned long long n, t_formaitem *format, char *base,
		char *spe)
{
	char	*ret;
	int		size;

	size = format->precision;
	if ((format->flags & 256 && (format->flags & 512 || format->flags & 32))
			&& (size != 0 || format->flags & 32))
		size -= ft_strlen(spe);
	if (size < size_llxtoa(n, base) && !(n == 0 && size == 0))
		size = size_llxtoa(n, base);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ft_putinstr(ret, n, size, base);
	ret[size] = 0;
	if ((format->flags & 256 && n != 0) || format->flags & 128)
		ret = ft_strfreejoin(ft_strdup(spe), ret);
	return (ret);
}
