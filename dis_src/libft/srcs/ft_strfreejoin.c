/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:59:12 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 13:41:20 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreejoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	free(s1);
	free(s2);
	return (ret);
}

char	*ft_strnjoin(char *s1, char *s2, int n1, int n2)
{
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_strnew(n1 + n2);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, n1);
	ft_memcpy(&ret[n1], s2, n2);
	free(s1);
	free(s2);
	return (ret);
}
