/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:57:09 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/13 12:22:18 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrword(char const *s, char c)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] != c && s[i] != 0)
				i++;
			if (s[i] == 0)
				break ;
		}
		i++;
	}
	return (ret);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	*ft_copyword(char const *s, char c)
{
	char	*ret;
	int		i;

	ret = (char*)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ft_wordlen(s, c))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (ft_nbrword(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			ret[j] = ft_copyword(&s[i], c);
			i += ft_wordlen(&s[i], c);
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}
