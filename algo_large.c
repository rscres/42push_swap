/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/21 12:46:10 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_dbl_list *stack)
{
	int			min;
	t_dbl_list	*tmp;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_dbl_list *stack)
{
	int			max;
	t_dbl_list	*tmp;

	tmp = stack;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

t_dbl_list	*move_to_b(t_dbl_list *stack_a, t_dbl_list *stack_b, int b_min, int b_max)
{
	t_dbl_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value < b_min || tmp->value > b_max)
		{
			push_b(&stack_a, &stack_b);
			tmp = stack_a;
		}
		else
			tmp = tmp->next;
	}
	return (stack_b);
}

void	algo_large(t_dbl_list **stack_a)
{
	t_dbl_list	**stack_b;
	int			b_min;
	int			b_max;

	stack_b = malloc(sizeof(t_dbl_list *));
	*stack_b = NULL;
	while (ft_dbl_lstsize(*stack_b) < 2)
		push_b(stack_a, stack_b);
	b_min = find_min(*stack_b);
	b_max = find_max(*stack_b);
	while (ft_dbl_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->value < b_min
			|| (*stack_a)->value > b_max)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	algo_3arg(stack_a);
	// while (*stack_b)
	// {	
	// 	if ((*stack_a)->value >)
	// 	push_a(stack_b, stack_a);
	// }
	print_list(*stack_a);
	printf("stack_b\n");
	print_list(*stack_b);
}
