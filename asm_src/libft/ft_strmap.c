/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:04:43 by tlux              #+#    #+#             */
/*   Updated: 2017/11/16 22:04:44 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char				*ret;
	unsigned int		i;

	if (!s || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(s[i]);
		i++;
	}
	return (ret);
}
