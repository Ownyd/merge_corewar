/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:46:20 by tlux              #+#    #+#             */
/*   Updated: 2018/03/02 17:19:50 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delspaces(char *str)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	tmp = ft_strtrim(str);
	len = ft_strlen(tmp);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == ' ' || tmp[i] == '\t')
		{
			tmp = ft_strfreejoin(ft_strsub(tmp, 0, i),
					ft_strfreesub(tmp, i + 1, len), 3);
		}
		else
			i++;
	}
	return (tmp);
}
