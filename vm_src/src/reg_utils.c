/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:10:14 by lowczarc          #+#    #+#             */
/*   Updated: 2018/03/07 17:33:36 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reg_clone(unsigned char *reg, unsigned char *to_clone)
{
	int	i;

	i = -1;
	while (++i < REG_SIZE)
		reg[i] = to_clone[i];
}

void	reg_charge(unsigned char *reg, long long nb)
{
	unsigned long	i;

	i = 0;
	while (i < sizeof(nb) && i < REG_SIZE)
	{
		reg[REG_SIZE - i - 1] = (nb >> (i * 8)) & 0xFF;
		i++;
	}
}

void	reg_print(unsigned char *reg)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		ft_printf("%.2hhx", reg[i]);
		i++;
		if (i < REG_SIZE)
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
}
