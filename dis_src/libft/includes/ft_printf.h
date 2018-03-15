/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:47:08 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/10 12:27:56 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_formaitem
{
	char			format;
	int				flags;
	int				precision;
	int				min_size;
}					t_formaitem;

typedef	struct		s_format
{
	char			c;
	char			*(*fonct)();
	unsigned int	flag;
}					t_format;

typedef	struct		s_flags
{
	char			*str;
	unsigned int	flag;
}					t_flags;

int					ft_modifier(char **str);
int					ft_flag(char **str);
int					ft_isformat(char c);
void				*ft_fonctformat(char c, t_formaitem *format);
char				*string_format(va_list ap, t_formaitem *format, int *size);
char				*int_format(va_list ap, t_formaitem *format, int *size);
char				*wstr_to_str(wchar_t *str, int size);
char				*wchar_to_str(wchar_t c);
size_t				ft_wstrlen(wchar_t *str);
char				*char_format(va_list ap, t_formaitem *format, int *size);
char				*float_format(va_list ap, t_formaitem *format, int *size);
char				*pourcent_format(va_list ap, t_formaitem *format,
		int *size);
int					ft_printf(char *format, ...);
void				ft_putnstr(char *str, int size);
char				*ft_strnjoin(char *s1, char *s2, int n1, int n2);
char				*ft_strfreejoin(char *s1, char *s2);
char				*ft_llitoa(long long int n, t_formaitem *format);
char				*ft_llutoa(unsigned long long int n, int size);
char				*ft_llxtoa(unsigned long long int n, t_formaitem *format,
		char *base, char *spe);
size_t				ft_putstrfinalc(char **str, char c);
size_t				ft_strlenc(const char *s, char c);

#endif
