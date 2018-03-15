/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:58:56 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/15 17:41:12 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_space(const char *s)
{
	int	tmp;
	int	ret;
	int i;

	i = 0;
	ret = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			tmp++;
		else
		{
			ret += tmp + 1;
			tmp = 0;
		}
		i++;
	}
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	ret = (char*)malloc(sizeof(char) * (strlen_space(&s[i]) + 1));
	if (ret == NULL)
		return (NULL);
	j = 0;
	k = strlen_space(&s[i]);
	while (k - j)
	{
		ret[j] = s[i + j];
		j++;
	}
	ret[j] = 0;
	return (ret);
}
