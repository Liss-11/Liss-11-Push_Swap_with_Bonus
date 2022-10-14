/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov_and_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:41:12 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 18:25:50 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/checker.h"

void	ch_sa_action(t_stack *a)
{
	if (a->length > 1)
		mov_sa_sb_ss(a);
	return ;
}

void	ch_sb_action(t_stack *b)
{
	if (b->length > 1)
		mov_sa_sb_ss(b);
	return ;
}

void	ch_ss_action(t_stack *a, t_stack *b)
{
	if (a->length > 1 || b->length > 1)
	{	
		mov_sa_sb_ss(a);
		mov_sa_sb_ss(b);
	}
	return ;
}

void	mov_sa_sb_ss(t_stack *stack)
{
	t_element	*tmp;

	if (stack->length > 1)
	{
		tmp = stack->top_element->next;
		if (stack->length == 2)
		{
			tmp->next = stack->top_element;
			tmp->prev = NULL;
			stack->top_element->prev = tmp;
			stack->top_element->next = NULL;
			stack->top_element = tmp;
			stack->bottom_element = tmp->next;
		}
		if (stack->length > 2)
		{
			stack->top_element->next->next->prev = stack->top_element;
			stack->top_element->next = stack->top_element->next->next;
			tmp->next = stack->top_element;
			tmp->prev = NULL;
			stack->top_element->prev = tmp;
			stack->top_element = tmp;
		}
	}
}
