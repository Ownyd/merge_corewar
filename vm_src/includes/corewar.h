/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:46:15 by emarin            #+#    #+#             */
/*   Updated: 2018/03/15 16:03:54 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "op.h"
# include "visu_ncurses.h"

typedef struct		s_process
{
	unsigned char				regs[REG_NUMBER * REG_SIZE];
	long long					pc;
	char						carry;
	int							nblive;
	int							cycles;
	char						*instr;
	int							player;
	struct s_process			*next;
}					t_process;

typedef struct		s_player
{
	long long	num;
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	int			prog_size;
	char		*prog;
	int			cycle_last_live;
	int			nb_lives;
}					t_player;

typedef struct		s_vm
{
	long long	cycle;
	int			nblive;
	t_process	*process;
	int			nb_player;
	char		*arena;
	t_player	*players;
	int			cycle_to_die;
	int			dump_nbr_cycles;
	int			visu;
	t_visu		*visual;
	int			nblive_tot;
	int			time_last_reduction;
}					t_vm;

typedef struct		s_op
{
	char	*name;
	int		opcode;
	int		arg[4];
	int		index;
	int		cycles;
	char	*descr;
	int		ocp;
	int		dir_size;
	int		(*fonct)();
}					t_op;

char				charge_instr(t_process *process, t_vm *vm);
char				charge_name_instr(t_process *process, t_vm *vm);
long long			arena_to_ll(char *arena, int start);
long long			get_param(int nb, t_process *process, char *arena, int *i);
char				fork_process(t_process **process, long long pc,
		t_process *to_fork, t_vm *vm);
void				print_arena(t_vm *vm);
void				ft_arenacpy(unsigned char *dest, char *arena, int start,
		int size);
void				arenacharge(t_vm *vm, unsigned char *src, long stsi,
		int player);
void				charge_memory(t_vm *vm);
int					store_prog(int fd, char *name, t_player *player);
int					check_magic(int fd);
char				ft_overflow(char *str);
char				ft_isnumber(char *str);
int					ft_er(char *message);
int					usage(int code);
char				init_vm(t_vm *vm);
int					close_vm(t_vm *vm, int code);
void				set_player_nb(t_vm *vm, char *player_nb);
int					player_nb_exist(t_vm *vm, char *player_nb, int nb);
void				reg_print(unsigned char *reg);
void				reg_charge(unsigned char *reg, long long nb);
void				reg_clone(unsigned char *reg, unsigned char *to_clone);
char				add_process(t_process **process, long long pc
, long long num_player, int player);
void				remove_process(t_process **process, t_process *to_del);
void				free_all_process(t_process *process);
void				print_process(t_process *process);
char				loop_vm(t_vm *vm);
char				process_execution(t_process *process, t_vm *vm);
int					size_instr(char instr, char *arg);
t_op				*get_op_by_id(unsigned char index);
long long			par_to_ll(char *param, int par_size);
void				print_winner(t_vm *vm);
unsigned char		*and_or_xor_loop(t_process *process, t_vm *vm
, long long *val);

void				reg_and(char *reg1, char *reg2, char *reg3);
void				reg_or(char *reg1, char *reg2, char *reg3);
void				reg_xor(char *reg1, char *reg2, char *reg3);
void				reg_add(char *reg1, char *reg2, char *reg3);
void				reg_sub(char *reg1, char *reg2, char *reg3);

int					op_live(t_process *process, t_vm *vm);
int					op_ld(t_process *process, t_vm *vm);
int					op_st(t_process *process, t_vm *vm);
int					op_add(t_process *process, t_vm *vm);
int					op_sub(t_process *process, t_vm *vm);
int					op_and(t_process *process, t_vm *vm);
int					op_or(t_process *process, t_vm *vm);
int					op_xor(t_process *process, t_vm *vm);
int					op_zjmp(t_process *process, t_vm *vm);
int					op_ldi(t_process *process, t_vm *vm);
int					op_sti(t_process *process, t_vm *vm);
int					op_fork(t_process *process, t_vm *vm);
int					op_lld(t_process *process, t_vm *vm);
int					op_lldi(t_process *process, t_vm *vm);
int					op_lfork(t_process *process, t_vm *vm);
int					op_aff(t_process *process, t_vm *vm);

static const t_op g_op[] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &op_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &op_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &op_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &op_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, &op_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &op_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &op_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &op_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &op_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, &op_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, &op_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &op_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &op_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, &op_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &op_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &op_aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL}
};

void				init_visu_ncurses(t_vm *vm);
void				close_visu_ncurses(t_vm *vm);
void				visu_ncurses(t_vm *vm);
void				visu_print_arena(t_vm *vm);
void				visu_print_gui(t_vm *vm);
int					count_nb_process(t_process *process);
void				print_title(t_vm *vm);
void				print_player(t_vm *vm, t_player *player, int i);
void				sleep_visu(t_vm *vm);
t_process			*get_last_process_at_pc(t_vm *vm, int pc);
void				visu_print_winner(t_vm *vm);

#endif
