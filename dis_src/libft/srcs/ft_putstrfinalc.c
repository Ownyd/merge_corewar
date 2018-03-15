/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrfinalc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:21:20 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/10 13:11:40 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putstrcolor(char **str)
{
	if (**str != '{')
		return (NULL);
	if (ft_strstr(*str, "{eoc}") == *str)
		return ("\033[0m");
	if (ft_strstr(*str, "{black}") == *str)
		return ("\033[30m");
	if (ft_strstr(*str, "{red}") == *str)
		return ("\033[31m");
	if (ft_strstr(*str, "{green}") == *str)
		return ("\033[32m");
	if (ft_strstr(*str, "{orange}") == *str)
		return ("\033[33m");
	if (ft_strstr(*str, "{blue}") == *str)
		return ("\033[34m");
	if (ft_strstr(*str, "{pink}") == *str)
		return ("\033[35m");
	if (ft_strstr(*str, "{cyan}") == *str)
		return ("\033[36m");
	if (ft_strstr(*str, "{white}") == *str)
		return ("\033[37m");
	return (NULL);
}

size_t	ft_putstrfinalc(char **str, char c)
{
	size_t		len;

	len = 0;
	while (**str != c && **str)
	{
		if (ft_putstrcolor(str))
		{
			write(1, ft_putstrcolor(str), ft_strlen(ft_putstrcolor(str)));
			len += ft_strlen(ft_putstrcolor(str));
			*str += ft_strlenc(*str, '}') + 1;
		}
		else
		{
			write(1, (*str)++, 1);
			len++;
		}
	}
	return (len);
}
