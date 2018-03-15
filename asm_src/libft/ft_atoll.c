/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 02:32:34 by tlux              #+#    #+#             */
/*   Updated: 2018/02/27 00:00:58 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	long long	ret;
	int			neg;

	neg = 1;
	ret = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-' && (neg = -1) == -1)
		str++;
	if (*str == '+' && *(str - 1) != '-')
		str++;
	while (*str != '\0' && *str != '+' && *str != '-')
	{
		if (*str < 10 + '0' && *str >= 0 + '0')
			ret = ret * 10 + (*str - '0');
		else
			return (ret * neg);
		str++;
	}
	return (ret * neg);
}
