/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 00:00:33 by tlux              #+#    #+#             */
/*   Updated: 2018/03/15 16:01:19 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# include "../libft/libft.h"
# include "op.h"

typedef struct		s_output
{
	char			c;
	struct s_output	*next;
}					t_otp;
typedef struct		s_label
{
	char			*label;
	int				octet;
	struct s_label	*next;
}					t_label;
typedef struct		s_cmds
{
	char			*cmd;
	int				opc;
	struct s_cmds	*next;
}					t_cmds;
int					name_error(int err, char *tmp);
int					get_fd(int cmd, int fd);
int					conv_hexa(char *str);
int					hexa_form(char *str);
int					read_in_field(int i, int size);
int					validity_label(char *line);
int					validity_opc(char *line);
int					validity_command_line(char *line);
int					ft_init_var(int *print, int *shift, int *i);
void				ft_outputdel(t_otp **todel);
t_otp				*ft_outputnew(int opc);
void				ft_outputadd(t_otp **alst, t_otp *new);
t_cmds				*ft_cmdnew(char *cmd, int opc);
void				ft_cmdadd(t_cmds **alst, t_cmds *new);
void				ft_cmddel(t_cmds **todel);
void				ft_labeladd(t_label **alst, t_label *new);
void				ft_labeldel(t_label **todel);
void				ft_putstrlen(char const *s, int len);
char				*ft_delspaces(char *str);
void				opc_params(char *params, int octet, int opc);
int					store_label(char *label, int octet, int cmd);
int					commandlist(char *cmd, int todo);
t_label				*ft_labelnew(char *str, int octet);
int					end_utils(int ac, char **av);
int					init_utils(int ac, char **av);
void				main_error(char *line, int i);
int					line_error(int err);
int					label_error(int err);
int					comment_error(int err, char *tmp);
void				delspaces_tab(char **tab);
int					param_error(int err, char **todel);
int					indir_error(int err);
int					dir_error(int err);
int					reg_error(int err);
void				store_output(int c, int cmd, int fd);
int					validity_params(int opc, char *params);
int					validity_line(char *line);
void				print_bits(int toprint, int size);
int					add_infos(char *info, char *line, int size, int cmd);
int					store_label(char *label, int octet, int cmd);
void				delete_comments(char **line);
void				first_parse(int fd);

#endif
