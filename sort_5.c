/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:53:12 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/25 20:38:42 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place(t_dbl_list *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value > value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_last_value(t_dbl_list *stack)
{
	t_dbl_list	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

static void	larger_than_max(t_dbl_list **stack_a, t_dbl_list **stack_b,
	int lst_size)
{
	while ((*stack_a)->value != find_min(*stack_a))
		rotate_a(stack_a);
	push_a(stack_b, stack_a);
	while ((*stack_a)->value != find_min(*stack_a)
		&& ft_dbl_lstsize(*stack_a) == lst_size)
		rotate_a(stack_a);
}

static void	middle_value(t_dbl_list **stack_a, t_dbl_list **stack_b,
	int lst_size)
{
	if ((*stack_b)->value > (*stack_a)->value
		&& (*stack_b)->value > (*stack_a)->next->value)
		while ((*stack_b)->value > (*stack_a)->value
			|| (*stack_b)->value < ft_last_value(*stack_a))
			reverse_rotate_a(stack_a);
	else
		while ((*stack_b)->value > (*stack_a)->value
			|| (*stack_b)->value < ft_last_value(*stack_a))
			rotate_a(stack_a);
	push_a(stack_b, stack_a);
	while ((*stack_a)->value != find_min(*stack_a)
		&& ft_dbl_lstsize(*stack_a) == lst_size)
		reverse_rotate_a(stack_a);
}

void	algo_5elem(t_dbl_list **stack_a)
{
	t_dbl_list	*stack_b;
	int			lst_size;

	lst_size = ft_dbl_lstsize(*stack_a);
	stack_b = NULL;
	push_b(stack_a, &stack_b);
	if (ft_dbl_lstsize(*stack_a) > 3)
		push_b(stack_a, &stack_b);
	algo_3arg(stack_a);
	while (ft_dbl_lstsize(*stack_a) <= 5)
	{
		if (check_sorted(*stack_a) && ft_dbl_lstsize(*stack_a) == lst_size)
			return ;
		if (stack_b->value < find_min(*stack_a))
		{
			while ((*stack_a)->value != find_min(*stack_a))
				reverse_rotate_a(stack_a);
			push_a(&stack_b, stack_a);
		}
		else if (stack_b->value > find_max(*stack_a))
			larger_than_max(stack_a, &stack_b, lst_size);
		else if (stack_b->value < find_max(*stack_a)
			&& stack_b->value > find_min(*stack_a))
			middle_value(stack_a, &stack_b, lst_size);
	}
}