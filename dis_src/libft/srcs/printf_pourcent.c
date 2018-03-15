/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pourcent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:50:08 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/08 12:03:55 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*pourcent_format(va_list ap, t_formaitem *format, int *size)
{
	char	*ret;

	(void)ap;
	ret = ft_memalloc(2);
	ret[0] = format->format;
	*size = 1;
	if (format->format == 0)
		*size = 0;
	return (ret);
}
