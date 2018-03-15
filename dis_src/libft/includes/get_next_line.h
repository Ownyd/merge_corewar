/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:06:29 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/15 22:14:34 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#include "libft.h"
#define BUFF_SIZE 32

typedef struct	s_filesbuff
{
	int		i;
	int		*t;
	char	**buff;
}				t_filesbuff;

int				get_next_line(const int fd, char **line);

#	endif
