/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucctions_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:48:43 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 18:18:32 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/checker.h"

void	read_instructions(char *line, t_stack *a, t_stack *b, int *no_move)
{
	if (!ft_strncmp(line, "sa\n", 5))
		ch_sa_action(a);
	else if (!ft_strncmp(line, "sb\n", 5))
		ch_sb_action(b);
	else if (!ft_strncmp(line, "ss\n", 5))
		ch_ss_action(a, b);
	else if (!ft_strncmp(line, "rra\n", 5))
		ch_rra_action(a);
	else if (!ft_strncmp(line, "rrb\n", 5))
		ch_rrb_action(b);
	else if (!ft_strncmp(line, "rrr\n", 5))
		ch_rrr_action(a, b);
	else if (!ft_strncmp(line, "ra\n", 5))
		ch_ra_action(a);
	else if (!ft_strncmp(line, "rb\n", 5))
		ch_rb_action(b);
	else if (!ft_strncmp(line, "rr\n", 5))
		ch_rr_action(a, b);
	else if (!ft_strncmp(line, "pa\n", 5))
		ch_pa_action(a, b);
	else if (!ft_strncmp(line, "pb\n", 5))
		ch_pb_action(a, b);
	else
		*no_move = 1;
}

void	is_ordered(t_stack *a, t_stack *b)
{
	t_element	*first;
	t_element	*second;
	int			count;

	count = 0;
	first = a->top_element;
	if (b->length != 0)
		incorrect(a, b);
	while (first->next)
	{
		second = first->next;
		if (first->index > second->index)
			count++;
		first = second;
	}
	if (count == 0)
	{
		write(1, "OK", 2);
		write(1, "\n", 1);
		return ;
	}
	incorrect(a, b);
}
