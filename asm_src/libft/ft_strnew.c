/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:05:00 by tlux              #+#    #+#             */
/*   Updated: 2017/11/16 22:09:15 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
