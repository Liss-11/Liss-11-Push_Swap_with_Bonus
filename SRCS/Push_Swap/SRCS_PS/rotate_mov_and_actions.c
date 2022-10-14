/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mov_and_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:17:48 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 15:01:10 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/push_swap.h"

void	ra_action(t_stack *a)
{
	if (a->length > 1)
	{
		mov_ra_rb_rr(a);
		write(1, "ra\n", 3);
	}
}

void	rb_action(t_stack *b)
{
	if (b->length < 2)
		return ;
	mov_ra_rb_rr(b);
	write(1, "rb\n", 3);
}

void	rr_action(t_stack *a, t_stack *b)
{
	if (a->length > 1 || b->length > 1)
	{
		mov_ra_rb_rr(a);
		mov_ra_rb_rr(b);
		write(1, "rr\n", 3);
	}
}

void	mov_ra_rb_rr(t_stack *stack)
{
	t_element	*tmp;

	if (stack->length < 2)
		return ;
	tmp = stack->top_element;
	stack->top_element = tmp->next;
	stack->top_element->prev = NULL;
	tmp->prev = stack->bottom_element;
	tmp->next = NULL;
	stack->bottom_element->next = tmp;
	stack->bottom_element = tmp;
}
