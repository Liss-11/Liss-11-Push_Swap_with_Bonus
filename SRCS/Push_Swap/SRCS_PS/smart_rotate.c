/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:02:27 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 17:36:03 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/push_swap.h"

int	smart_rotate_direct(int num, t_stack *stack, int *mov, int num_pos)
{
	int			mid;
	t_element	*top;

	mid = stack->length / 2;
	top = stack->top_element;
	while (top != NULL)
	{
		if (top->index == num)
			break ;
		num_pos++;
		top = top->next;
	}
	if (num_pos == 0)
		return (NUM_IN_TOP);
	if (num_pos < mid)
	{
		*mov = num_pos;
		return (ROTATE_NORM);
	}	
	if (num_pos >= mid)
	{
		*mov = stack->length - num_pos;
		return (ROTATE_REV);
	}
	return (NUM_NOT_FOUND);
}

void	put_num_in_top_a(int num, t_stack *a)
{
	int	rotate;
	int	num_pos;
	int	mov;
	int	x;

	num_pos = 0;
	x = 0;
	mov = 0;
	rotate = smart_rotate_direct(num, a, &mov, num_pos);
	if (rotate == NUM_IN_TOP)
		return ;
	if (rotate == NUM_NOT_FOUND)
		return ;
	if (rotate == ROTATE_NORM)
	{
		while (++x <= mov)
			ra_action(a);
	}
	if (rotate == ROTATE_REV)
	{
		while (++x <= mov)
			rra_action(a);
	}
}

void	put_num_in_top_b(int num, t_stack *a, t_stack *b)
{
	int	rotate;
	int	num_pos;
	int	mov;
	int	x;

	num_pos = 0;
	x = 0;
	mov = 0;
	rotate = smart_rotate_direct(num, b, &mov, num_pos);
	if (rotate == NUM_IN_TOP)
		return ;
	if (rotate == NUM_NOT_FOUND)
		return ;
	if (rotate == ROTATE_NORM)
		rotate_norm_b(a, b, num, mov);
	if (rotate == ROTATE_REV)
		rotate_rev_b(a, b, num, mov);
}

void	rotate_norm_b(t_stack *a, t_stack *b, int num, int mov)
{
	int			x;

	x = 0;
	while (++x <= mov)
	{
		if (b->top_element->index == (num - 1))
		{
			pa_action(a, b);
		}
		else if (b->top_element->index == (num - 2))
		{
			pa_action(a, b);
			ra_action(a);
		}
		else
			rb_action(b);
	}
}

void	rotate_rev_b(t_stack *a, t_stack *b, int num, int mov)
{
	int	x;

	x = 0;
	while (++x <= mov)
	{
		if (b->top_element->index == (num - 1))
		{
			pa_action(a, b);
			mov += 1;
		}
		else if (b->top_element->index == (num - 2))
		{
			pa_action(a, b);
			ra_action(a);
			mov += 1;
		}
		else
			rrb_action(b);
	}
}
