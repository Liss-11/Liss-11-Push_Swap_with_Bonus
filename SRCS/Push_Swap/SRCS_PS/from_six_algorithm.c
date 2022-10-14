/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_six_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:30:18 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 14:45:16 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/push_swap.h"

void	from_six_numbers(t_stack *a, t_stack *b, int n_chunks, int cnt)
{
	int	cut;
	int	x;

	cut = a->length / n_chunks;
	while (++cnt < n_chunks)
	{
		x = 0;
		while (x < cut)
		{
			if (a->top_element->index < cut)
			{	
				order_stack_b(a, b, cut);
				x++;
			}
			else
				ra_action(a);
		}
		assign_index(a);
	}
	while (a->length != 0)
		order_stack_b(a, b, cut);
	assign_index(b);
	return_to_stack_a(a, b);
}

void	order_stack_b(t_stack *a, t_stack *b, int cut)
{
	pb_action(a, b);
	if (b->top_element->index < (cut / 2))
		rb_action(b);
}

void	return_to_stack_a(t_stack *a, t_stack *b)
{
	while (b->length != 0)
	{
		put_num_in_top_b((max_index_b(b)), a, b);
		pa_action(a, b);
		check_order_stack_a(a);
	}
}

int	max_index_b(t_stack *b)
{
	t_element	*tmp;
	int			index;

	tmp = b->top_element;
	index = b->length - 1;
	while (tmp->next)
	{
		if (tmp->index == (index + 1))
			return (b->length);
		tmp = tmp->next;
	}
	if (tmp->index == (index + 1))
		return (b->length);
	return (index);
}

void	check_order_stack_a(t_stack *a)
{
	if (a->length > 1 && a->top_element->index != 0
		&& a->top_element->next->index == (a->top_element->index - 1))
		sa_action(a);
	if (a->length > 1 && a->top_element->index != 0
		&& a->bottom_element->index < a->bottom_element->prev->index)
		rra_action(a);
}
