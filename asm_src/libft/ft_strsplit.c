/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:21:25 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 18:35:39 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nbrword(char const *s, char *str)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != 0)
	{
		if (ft_strchr(str, s[i]) == 0)
		{
			ret++;
			while (ft_strchr(str, s[i]) == 0 && s[i] != 0)
				i++;
			if (s[i] == 0)
				break ;
		}
		i++;
	}
	return (ret);
}

static int	ft_wordlen(char const *s, char *str)
{
	int	i;

	i = 0;
	while (ft_strchr(str, s[i]) == 0 && s[i] != 0)
		i++;
	return (i);
}

static char	*ft_copyword(char const *s, char *str)
{
	char	*ret;
	int		i;

	ret = (char*)malloc(sizeof(char) * (ft_wordlen(s, str) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ft_wordlen(s, str))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_strsplit(char const *s, char *str)
{
	char	**ret;
	int		i;
	int		j;

	if ((i = 0) == 0 && s == NULL)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (ft_nbrword(s, str) + 1))))
		return (NULL);
	j = 0;
	while (s[i] != 0)
	{
		if (j == ft_nbrword(s, str))
			break ;
		while (ft_strchr(str, s[i]))
			i++;
		if (s[i] != 0)
		{
			ret[j] = ft_copyword(&s[i], str);
			i += ft_wordlen(&s[i], str);
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}
