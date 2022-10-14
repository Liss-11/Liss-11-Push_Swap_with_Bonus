/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mov_and_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:41:36 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 18:21:40 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/checker.h"

void	ch_pa_action(t_stack *a, t_stack *b)
{
	if (b->length == 0)
		return ;
	mov_pa_pb(b, a);
}

void	ch_pb_action(t_stack *a, t_stack *b)
{
	if (a->length == 0)
		return ;
	mov_pa_pb(a, b);
}

static void	mov_in_stack_to(t_stack *to, t_element *tmp)
{
	if (to->length < 1)
	{
		to->top_element = tmp;
		to->bottom_element = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = to->top_element;
		to->top_element->prev = tmp;
		to->top_element = tmp;
	}
}

void	mov_pa_pb(t_stack *from, t_stack *to)
{
	t_element	*tmp;

	tmp = from->top_element;
	if (from->length > 1)
	{
		from->top_element = tmp->next;
		from->top_element->prev = NULL;
	}
	else
	{
		from->bottom_element = NULL;
		from->top_element = NULL;
	}
	mov_in_stack_to(to, tmp);
	--from->length;
	++to->length;
}
