/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:32:49 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/08 17:52:51 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (*s == (char)c && (!*s || ft_strrchr(&s[1], c) == NULL))
		return ((char*)s);
	if (!*s)
		return (NULL);
	return (ft_strrchr(&s[1], c));
}
