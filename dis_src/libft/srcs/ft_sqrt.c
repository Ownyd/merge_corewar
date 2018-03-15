/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zerevo <lowczarc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:38:46 by zerevo            #+#    #+#             */
/*   Updated: 2018/02/20 11:22:46 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int x)
{
	int	i;

	i = 0;
	while ((i * i) <= x)
		i++;
	return (i);
}