/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:38:05 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/10 00:30:50 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"

void	four_numbers(t_stack *a, t_stack *b)
{
	put_num_in_top_a(0, a);
	if (stack_in_order(a) == 1)
		return ;
	pb_action(a, b);
	assign_index(a);
	three_numbers(a);
	pa_action(a, b);
}

void	five_numbers(t_stack *a, t_stack *b)
{
	put_num_in_top_a(0, a);
	if (stack_in_order(a) == 1)
		return ;
	pb_action(a, b);
	put_num_in_top_a(1, a);
	if (stack_in_order(a) == 1)
	{
		pa_action(a, b);
		return ;
	}
	pb_action(a, b);
	assign_index(a);
	three_numbers(a);
	pa_action(a, b);
	pa_action(a, b);
}
