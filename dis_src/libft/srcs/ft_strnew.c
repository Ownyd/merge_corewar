/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:06:27 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/09 22:30:22 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
