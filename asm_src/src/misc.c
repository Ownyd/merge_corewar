/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:29:49 by tlux              #+#    #+#             */
/*   Updated: 2018/03/25 17:45:12 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asm.h"

int	conv_hexa(char *str)
{
	int len;
	int i;
	int ret;

	ret = 0;
	i = -1;
	len = ft_strlen(str) - 1;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]))
			ret += (str[i] - 48) * ft_pow(16, len);
		else if (str[i] >= 65 && str[i] <= 70)
			ret += (str[i] - 55) * ft_pow(16, len);
		else if (str[i] >= 97 && str[i] <= 102)
			ret += (str[i] - 87) * ft_pow(16, len);
		len--;
	}
	return (ret);
}

int	hexa_form(char *str)
{
	int i;

	i = 2;
	if (!str || ft_strlen(str) > 10 ||
			ft_strlen(str) <= 2 || str[0] != '0' || !ft_strchr("xX", str[1]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_strchr("0123456789aAbBcCdDeEfF", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validity_command_line(char *line, t_utils utils)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (ft_strchr("\t ", line[j]))
		j++;
	while (ft_strchr(LABEL_CHARS, line[i + j]))
		i++;
	if (line[i + j] == LABEL_CHAR && !validity_label(line + j, utils))
		return (0);
	else if (line[i + j] != LABEL_CHAR && !validity_opc(line, utils))
		return (0);
	return (1);
}

int	read_in_field(int i, int size, int fd)
{
	char	*buf;
	int		j;
	int		ret;

	i++;
	while ((ret = get_next_line(fd, &buf)) == 1)
	{
		j = 0;
		while (buf[j] != '\0' && buf[j] != '"' && (++i))
			j++;
		if (ft_strocur(buf, '"') > 1)
			i = size;
		if (++i > size)
			break ;
		if (buf[j] == '"')
		{
			if (buf[j + 1] != '\0' && buf[j + 1] != '#')
				ret = 0;
			break ;
		}
		free(buf);
	}
	free(buf);
	return (ret == 0 ? size + 1 : i);
}

int	ft_init_var(int *print, int *shift, int *i)
{
	*print = 0;
	*shift = 6;
	*i = -1;
	return (1);
}
