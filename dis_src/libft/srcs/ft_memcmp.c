/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:59:40 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/08 13:17:48 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	if (*((unsigned char*)s1) != *((unsigned char*)s2))
		return (*((unsigned char*)s1) - *((unsigned char*)s2));
	return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
}
