/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:34:57 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/12 14:35:11 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2 || !*s1)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strcmp(&s1[1], &s2[1]));
}
