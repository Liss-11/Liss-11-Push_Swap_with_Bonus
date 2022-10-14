/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:49:52 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/14 13:34:34 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/checker.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		no_move;

	no_move = 0;
	if (argc <= 1)
		return (0);
	check_errors(argc, argv);
	init_stack_a (&a, argc, argv);
	init_stack_b (&b);
	assign_index (&a);
	reader(&a, &b, &no_move);
	is_ordered(&a, &b);
	free_all(&a);
	return (0);
}

void	reader(t_stack *a, t_stack *b, int *no_move)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		read_instructions(line, a, b, no_move);
		if (*no_move == 1)
		{
			free(line);
			if (a->length > 0)
				free_all(a);
			if (b->length > 0)
				free_all(b);
			print_error();
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit (-1);
}

void	incorrect(t_stack *a, t_stack *b)
{
	if (a->length > 0)
		free_all(a);
	if (b->length > 0)
		free_all(b);
	write(1, "KO", 2);
	write(1, "\n", 1);
	exit (0);
}

void	free_all(t_stack *stack)
{
	t_element	*tmp;

	while (stack->top_element->next != NULL)
	{
		tmp = stack->top_element;
		stack->top_element = tmp->next;
		free(tmp);
	}
	free(stack->top_element);
}
