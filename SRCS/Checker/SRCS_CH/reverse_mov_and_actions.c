/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_mov_and_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:47:01 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 18:22:46 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/checker.h"

void	ch_rra_action(t_stack *a)
{
	if (a->length > 1)
		mov_rra_rrb_rrr(a);
	return ;
}

void	ch_rrb_action(t_stack *b)
{
	if (b->length > 1)
		mov_rra_rrb_rrr(b);
	return ;
}

void	ch_rrr_action(t_stack *a, t_stack *b)
{
	if (a->length > 1 || b->length > 1)
	{
		mov_rra_rrb_rrr(a);
		mov_rra_rrb_rrr(b);
	}
	return ;
}

void	mov_rra_rrb_rrr(t_stack *stack)
{
	t_element	*tmp;

	if (stack->length < 2)
		return ;
	tmp = stack->bottom_element;
	stack->bottom_element = tmp->prev;
	stack->bottom_element->next = NULL;
	tmp->next = stack->top_element;
	tmp->prev = NULL;
	stack->top_element->prev = tmp;
	stack->top_element = tmp;
}
