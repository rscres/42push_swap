/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:53:12 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/21 00:37:41 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_last_value(t_dbl_list *stack)
{
	t_dbl_list	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (*(int *)(tmp)->content);
}

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
	while (!check_sorted(*stack_a))
			algo_3arg(stack_a);
	min_a = find_min(*stack_a);
	max_a = find_max(*stack_a);
	min_b = find_min(stack_b);
	max_b = find_max(stack_b);
	if (max_a > max_b)
	{
		if (*(int *)(*stack_a)->content > *(int *)stack_b->content)
		{
			while (*(int *)(*stack_a)->content != max_a)
				reverse_rotate_a(stack_a);
		}
		else
		{
			while (*(int *)(*stack_a)->content != max_a)
				rotate_a(stack_a);
		}
		// while (*(int *)(*stack_a)->content != max_a)
		// 	rotate_a(stack_a);
		// while (*(int *)(stack_b)->content != max_b)
		// 	rotate_b(&stack_b);
		push_a(&stack_b, stack_a);
		if (*(int *)(*stack_a)->content > min_b && ft_last_value(*stack_a) > min_b)
			reverse_rotate_a(stack_a);
		push_a(&stack_b, stack_a);
		while (*(int *)(*stack_a)->content != find_min(*stack_a))
			reverse_rotate_a(stack_a);
	}
	else
	{
		if (*(int *)(*stack_a)->content > *(int *)stack_b->content)
		{
			while (*(int *)(*stack_a)->content != min_a)
				reverse_rotate_a(stack_a);
		}
		else
		{
			while (*(int *)(*stack_a)->content != min_a)
				rotate_a(stack_a);
		}
		while (*(int *)(stack_b)->content != max_b)
			reverse_rotate_b(&stack_b);
		push_a(&stack_b, stack_a);
		if (*(int *)stack_b->content < find_min(*stack_a))
			while(*(int *)(*stack_a)->content != find_min(*stack_a))
				reverse_rotate_a(stack_a);
		else
			while (*(int *)(*stack_a)->content > *(int *)stack_b->content && ft_last_value(*stack_a) > *(int *)stack_b->content)
			reverse_rotate_a(stack_a);
		push_a(&stack_b, stack_a);
		while (*(int *)(*stack_a)->content != find_min(*stack_a))
			reverse_rotate_a(stack_a);
	}
}
