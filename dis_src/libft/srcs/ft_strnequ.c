/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:58:16 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/13 12:24:30 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	const size_t	i = n;

	if (!s1 || !s2)
		return (0);
	while (s1[i - n] && s1[i - n] == s2[i - n])
		n--;
	return ((!s1[i - n] && !s2[i - n]) || !n);
}
