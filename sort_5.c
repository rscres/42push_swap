/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:53:12 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 20:43:08 by renato           ###   ########.fr       */
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
		rotate(stack_a, 1);
	push(stack_b, stack_a, 1);
	while ((*stack_a)->value != find_min(*stack_a)
		&& ft_dbl_lstsize(*stack_a) == lst_size)
		rotate(stack_a, 1);
}

static void	middle_value(t_dbl_list **stack_a, t_dbl_list **stack_b,
	int lst_size)
{
	if ((*stack_b)->value > (*stack_a)->value
		&& (*stack_b)->value > (*stack_a)->next->value)
		while ((*stack_b)->value > (*stack_a)->value
			|| (*stack_b)->value < ft_last_value(*stack_a))
			reverse_rotate(stack_a, 1);
	else
		while ((*stack_b)->value > (*stack_a)->value
			|| (*stack_b)->value < ft_last_value(*stack_a))
			rotate(stack_a, 1);
	push(stack_b, stack_a, 1);
	while ((*stack_a)->value != find_min(*stack_a)
		&& ft_dbl_lstsize(*stack_a) == lst_size)
		reverse_rotate(stack_a, 1);
}

void	sort_5elem(t_dbl_list **stack_a)
{
	t_dbl_list	*stack_b;
	int			lst_size;

	lst_size = ft_dbl_lstsize(*stack_a);
	stack_b = NULL;
	push(stack_a, &stack_b, 2);
	if (ft_dbl_lstsize(*stack_a) > 3)
		push(stack_a, &stack_b, 2);
	sort_3elem(stack_a);
	while (ft_dbl_lstsize(*stack_a) <= 5)
	{
		if (check_sorted(*stack_a) && ft_dbl_lstsize(*stack_a) == lst_size)
			return ;
		if (stack_b->value < find_min(*stack_a))
		{
			while ((*stack_a)->value != find_min(*stack_a))
				reverse_rotate(stack_a, 1);
			push(&stack_b, stack_a, 1);
		}
		else if (stack_b->value > find_max(*stack_a))
			larger_than_max(stack_a, &stack_b, lst_size);
		else if (stack_b->value < find_max(*stack_a)
			&& stack_b->value > find_min(*stack_a))
			middle_value(stack_a, &stack_b, lst_size);
	}
}
