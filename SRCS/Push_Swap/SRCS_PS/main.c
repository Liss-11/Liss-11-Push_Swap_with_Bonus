/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 01:43:28 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/10 15:37:32 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	check_errors(argc, argv);
	init_stack_a(&a, argc, argv);
	init_stack_b(&b);
	assign_index(&a);
	resolve(&a, &b);
	free_all(&a);
	return (0);
}

void	resolve(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = 0;
	if (a->length == 2)
		two_numbers(a);
	else if (a->length == 3)
		three_numbers(a);
	else if (a->length == 4)
		four_numbers(a, b);
	else if (a->length == 5)
		five_numbers(a, b);
	else if (a->length < 20)
		from_six_numbers(a, b, 2, cnt);
	else if (a->length < 101)
		from_six_numbers(a, b, 5, cnt);
	else
		from_six_numbers(a, b, 8, cnt);
}

int	stack_in_order(t_stack *a)
{
	t_element	*first;
	t_element	*second;
	int			count;

	count = 0;
	first = a->top_element;
	while (first->next)
	{
		second = first->next;
		if (first->index > second->index)
			count++;
		first = second;
	}
	if (count == 0)
		return (1);
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit (-1);
}

void	free_all(t_stack *a)
{
	t_element	*tmp;

	while (a->top_element->next != NULL)
	{
		tmp = a->top_element;
		a->top_element = tmp->next;
		free(tmp);
	}
	free(a->top_element);
}
