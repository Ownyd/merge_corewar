/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:36:57 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/07 17:37:23 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi_l(const char *str)
{
	int				i;
	int				sign;
	long	long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (sign * res);
}
