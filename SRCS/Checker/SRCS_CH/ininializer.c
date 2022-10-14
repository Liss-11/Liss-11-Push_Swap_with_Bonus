/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ininializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:19:12 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 17:53:41 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/checker.h"

static void	init_element(t_element *o, char *arg)
{
	o->value = ft_atoi(arg);
	o->next = NULL;
	o->prev = NULL;
}

void	init_stack_a(t_stack *a, int argc, char **argv)
{
	t_element	*new_element;
	t_element	*tmp;

	a->length = 0;
	a->top_element = NULL;
	a->bottom_element = NULL;
	while ((a->length + 1) < argc)
	{
		new_element = malloc(sizeof(t_element));
		init_element(new_element, argv[a->length + 1]);
		if (!a->top_element)
		{
			a->length++;
			a->top_element = new_element;
			a->bottom_element = new_element;
		}
		else
		{
			a->length++;
			tmp = a->bottom_element;
			a->bottom_element = new_element;
			tmp->next = a->bottom_element;
			a->bottom_element->prev = tmp;
		}
	}
}

void	init_stack_b(t_stack *b)
{
	b->length = 0;
	b->top_element = NULL;
	b->bottom_element = NULL;
}

void	assign_index(t_stack *stack)
{
	t_element	*tmp;
	t_element	*current;
	int			count;
	int			index;

	count = 0;
	current = stack->top_element;
	while (count < stack->length)
	{
		index = 0;
		tmp = stack->top_element;
		while (tmp != NULL)
		{
			if (current->value > tmp->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
		count++;
	}
}
