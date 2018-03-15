/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:23:25 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/13 12:34:51 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	if (*s1 != *s2 || !*s1 || !(n - 1))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strncmp(&s1[1], &s2[1], n - 1));
}
