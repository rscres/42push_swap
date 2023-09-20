/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:53:12 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/20 20:47:41 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_5elem(t_dbl_list **stack_a)
{
	int			min_a;
	int			max_a;
	int			min_b;
	int			max_b;
	t_dbl_list	*stack_b;

	stack_b = NULL;
	push_b(stack_a, &stack_b);
	push_b(stack_a, &stack_b);
	ft_printf("\n");
	print_list(*stack_a);
	ft_printf("\n");
	while (!check_sorted(*stack_a))
			algo_3arg(stack_a);
	print_list(*stack_a);
	print_list(stack_b);
	min_a = find_min(*stack_a);
	max_a = find_max(*stack_a);
	min_b = find_min(stack_b);
	max_b = find_max(stack_b);
	if (max_a > max_b)
	{
		while (*(int *)(*stack_a)->content != max_a)
			rotate_a(stack_a);
		while (*(int *)(stack_b)->content != max_b)
			rotate_b(&stack_b);
		while (stack_b)
			push_a(&stack_b, stack_a);
		while (*(int *)(*stack_a)->content != min_a)
			reverse_rotate_a(stack_a);
	}
	else
	{
		while (*(int *)(*stack_a)->content != min_a)
			reverse_rotate_a(stack_a);
		while (*(int *)(stack_b)->content != max_b)
			reverse_rotate_b(&stack_b);
		while (stack_b)
			push_a(&stack_b, stack_a);
		while (*(int *)(*stack_a)->content != min_a)
			rotate_a(stack_a);
	}
	ft_printf("\n");
	print_list(*stack_a);
}
