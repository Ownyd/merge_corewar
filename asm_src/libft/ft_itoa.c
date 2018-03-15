/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:21:34 by tlux              #+#    #+#             */
/*   Updated: 2017/11/16 22:29:57 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	size_itoa(int n)
{
	int	ret;

	ret = (n < 0);
	n = ((n < 0) ? -n : n);
	while (n >= 10)
	{
		ret++;
		n /= 10;
	}
	ret++;
	return (ret);
}

static int	ft_putinstr(char *s, int n)
{
	if (n == 0)
		return (0);
	ft_putinstr(s - 1, n / 10);
	*s = (n % 10) + '0';
	return (n);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ret = malloc(sizeof(char) * (size_itoa(n) + 1));
	if (ret == NULL)
		return (NULL);
	ret[size_itoa(n) + 1] = 0;
	if (n < 0)
	{
		ret[i++] = '-';
		n = ((n < 0) ? -n : n);
	}
	ft_putinstr(&ret[i + size_itoa(n) - 1], n);
	ret[i + size_itoa(n)] = 0;
	return (ret);
}
