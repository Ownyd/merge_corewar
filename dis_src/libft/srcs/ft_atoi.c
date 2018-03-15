/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:20:03 by lowczarc          #+#    #+#             */
/*   Updated: 2018/02/22 19:53:03 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnbr(char *str, int negative)
{
	unsigned long long	ret;

	ret = 0;
	while (ft_isdigit(*str))
	{
		ret = (ret * 10) + *str - '0';
		str++;
	}
	if (ret > 9223372036854775807)
	{
		if (!negative)
			return (-1);
		else
			return (0);
	}
	return ((int)((ret > 2147483647) ? 0 : ret));
}

int			ft_atoi(const char *str)
{
	char	*s;

	s = (char*)str;
	while (*s == '\t' || *s == '\n' || *s == '\r' || *s == '\v' || *s == '\f'
			|| *s == ' ')
		s++;
	if (!ft_strncmp(s, "-2147483648", 11) && !ft_isdigit(s[11]))
		return (-2147483648);
	if (*s == '-')
		return (-1 * ft_getnbr(&s[1], 1));
	if (*s == '+')
		s++;
	return (ft_getnbr(s, 0));
}
