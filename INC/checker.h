/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:06:41 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/14 01:34:22 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "../SRCS/Libft/INC/get_next_line.h"

//main

int			main(int argc, char **argv);
void		reader(t_stack *a, t_stack *b, int *no_move);
void		print_error(void);
void		incorrect(t_stack *a, t_stack *b);
void		free_all(t_stack *stack);

//check_errors

long int	ft_atoil(const char *str, int number, long int i);
void		check_errors(int argc, char **argv);
void		check_int(int argc, char **argv);
void		duplicated_num(int argc, char **argv);

//initializer

void		init_stack_a(t_stack *a, int argc, char **argv);
void		init_stack_b(t_stack *b);
void		assign_index(t_stack *stack);

//instructions_reader

void		read_instructions(char *line, t_stack *a, t_stack *b, int *no_move);
void		is_ordered(t_stack *a, t_stack *b);

//swap_mov_and_actions

void		mov_sa_sb_ss(t_stack *stack);
void		ch_sa_action(t_stack *a);
void		ch_sb_action(t_stack *b);
void		ch_ss_action(t_stack *a, t_stack *b);

//push_mov_and_actions

void		mov_pa_pb(t_stack *from, t_stack *to);
void		ch_pa_action(t_stack *a, t_stack *b);
void		ch_pb_action(t_stack *a, t_stack *b);

//rotate_mov_and_actions

void		mov_ra_rb_rr(t_stack *stack);
void		ch_ra_action(t_stack *a);
void		ch_rb_action(t_stack *b);
void		ch_rr_action(t_stack *a, t_stack *b);

//reverse_mov_and_actions

void		mov_rra_rrb_rrr(t_stack *stack);
void		ch_rra_action(t_stack *a);
void		ch_rrb_action(t_stack *b);
void		ch_rrr_action(t_stack *a, t_stack *b);

#endif
