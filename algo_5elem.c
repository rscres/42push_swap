/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:53:12 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/22 20:08:29 by rseelaen         ###   ########.fr       */
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

void	algo_5elem(t_dbl_list **stack_a)
{
	int			min_a;
	int			max_a;
	int			min_b;
	int			max_b;
	t_dbl_list	*stack_b;

	stack_b = NULL;
	push_b(stack_a, &stack_b);
	if (check_sorted(*stack_a))
	{
		while ((*stack_a)->value < stack_b->value)
			rotate_a(stack_a);
		push_a(&stack_b, stack_a);
		if (find_place(*stack_a, (*stack_a)->value)
			< ft_dbl_lstsize(*stack_a) / 2)
			while ((*stack_a)->value != find_min(*stack_a))
				reverse_rotate_a(stack_a);
		else
			while ((*stack_a)->value != find_min(*stack_a))
				rotate_a(stack_a);
		return ;
	}
	push_b(stack_a, &stack_b);
	while (ft_dbl_lstsize(*stack_a) == 3 && !check_sorted(*stack_a))
		algo_3arg(stack_a);
	while (ft_dbl_lstsize(*stack_a) <= 5)
	{
		if (check_sorted(*stack_a) && ft_dbl_lstsize(*stack_a) == 5)
			return ;
		print_list(*stack_a);
		if (stack_b->value < find_min(*stack_a))
		{
			printf("stack_b->value < find_min(*stack_a)\n");
			while ((*stack_a)->value != find_min(*stack_a))
				reverse_rotate_a(stack_a);
			push_a(&stack_b, stack_a);
		}
		else if (stack_b->value > find_max(*stack_a))
		{
			printf("stack_b->value > find_max(*stack_a)\n");
			while ((*stack_a)->value != find_min(*stack_a))
				rotate_a(stack_a);
			push_a(&stack_b, stack_a);
			if (!check_sorted(*stack_a))
				while ((*stack_a)->value != find_min(*stack_a))
					rotate_a(stack_a);
		}
		else if (stack_b->value < find_max(*stack_a)
			&& stack_b->value > find_min(*stack_a))
		{
			printf("stack_b->value < find_max(*stack_a)\n");
			while (stack_b->value < (*stack_a)->value
				&& stack_b->value > ft_last_value(*stack_a))
				rotate_a(stack_a);
			print_list(*stack_a);
			push_a(&stack_b, stack_a);
			while ((*stack_a)->value != find_min(*stack_a))
				reverse_rotate_a(stack_a);
		}
	}
}

	// // print_list(*stack_a);
	// while (!check_sorted(*stack_a))
	// 	algo_3arg(stack_a);
	// // print_list(*stack_a);
	// min_a = find_min(*stack_a);
	// max_a = find_max(*stack_a);
	// min_b = find_min(stack_b);
	// max_b = find_max(stack_b);
	// print_list(stack_b);
	// print_list(*stack_a);
	// while (stack_b && stack_b->value < min_a)
	// {
	// 	push_a(&stack_b, stack_a);
	// 	min_a = find_min(*stack_a);
	// }
	// if (check_sorted(*stack_a) && ft_dbl_lstsize(*stack_a) == 5)
	// 	return ;
	// if (check_sorted(*stack_a))
	// {
	// 	// printf("check_sorted\n");
	// 	while ((*stack_a)->value < stack_b->value)
	// 		rotate_a(stack_a);
	// 	push_a(&stack_b, stack_a);
	// 	if (find_place(*stack_a, (*stack_a)->value)
	// 		< ft_dbl_lstsize(*stack_a) / 2)
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			reverse_rotate_a(stack_a);
	// 	else
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			rotate_a(stack_a);
	// 	print_list(stack_b);
	// 	print_list(*stack_a);
	// 	return ;

	// }
	// if (check_sorted(*stack_a))
	// {
	// 	while ((*stack_a)->value < stack_b->value)
	// 		rotate_a(stack_a);
	// 	push_a(&stack_b, stack_a);
	// 	if (find_place(*stack_a, (*stack_a)->value)
	// 		< ft_dbl_lstsize(*stack_a) / 2)
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			reverse_rotate_a(stack_a);
	// 	else
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			rotate_a(stack_a);
	// 	print_list(stack_b);
	// 	print_list(*stack_a);
	// 	return ;
	// }
	// while (stack_b && stack_b->value > max_a)
	// {
	// 	push_a(&stack_b, stack_a);
	// 	max_a = find_max(*stack_a);
	// }
	// if (check_sorted(*stack_a) && ft_dbl_lstsize(*stack_a) == 5)
	// 	return ;
	// if (stack_b->value < (*stack_a)->value && stack_b->value > ft_last_value(*stack_a))
	// {
	// 	push_a(&stack_b, stack_a);
	// 	if (find_place(*stack_a, (*stack_a)->value)
	// 		< ft_dbl_lstsize(*stack_a) / 2)
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			reverse_rotate_a(stack_a);
	// 	else
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			rotate_a(stack_a);
	// 	print_list(stack_b);
	// 	print_list(*stack_a);
	// 	return ;
	// }
	// print_list(stack_b);
	// print_list(*stack_a);

	// // if (max_a > max_b)
	// // {
	// // 	if ((*stack_a)->value > stack_b->value)
	// // 	{
	// // 		while ((*stack_a)->value != max_a)
	// // 			reverse_rotate_a(stack_a);
	// // 	}
	// // 	else
	// // 	{
	// // 		while ((*stack_a)->value != max_a)
	// // 			rotate_a(stack_a);
	// // 	}
	// // 	push_a(&stack_b, stack_a);
	// // 	if ((*stack_a)->value > min_b && ft_last_value(*stack_a) > min_b)
	// // 		reverse_rotate_a(stack_a);
	// // 	else
	// // 		while ((*stack_a)->value < stack_b->value
	// // 			&& ft_last_value(*stack_a) < stack_b->value)
	// // 			rotate_a(stack_a);
	// // 	push_a(&stack_b, stack_a);
	// // 	while ((*stack_a)->value != find_min(*stack_a))
	// // 		reverse_rotate_a(stack_a);
	// // }
	// // else
	// // {
	// if ((*stack_a)->value > stack_b->value)
	// {
	// 	while ((*stack_a)->value != min_a)
	// 		reverse_rotate_a(stack_a);
	// }
	// else
	// {
	// 	while ((*stack_a)->value != min_a)
	// 		rotate_a(stack_a);
	// }
	// while (stack_b->value != max_b)
	// 	reverse_rotate_b(&stack_b);
	// push_a(&stack_b, stack_a);
	// if (stack_b->value < find_min(*stack_a))
	// 	while ((*stack_a)->value != find_min(*stack_a))
	// 		reverse_rotate_a(stack_a);
	// else
	// 	while ((*stack_a)->value > stack_b->value
	// 		&& ft_last_value(*stack_a) > stack_b->value)
	// 		reverse_rotate_a(stack_a);
	// push_a(&stack_b, stack_a);
	// if (find_place(*stack_a, (*stack_a)->value)
	// 		< ft_dbl_lstsize(*stack_a) / 2)
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			reverse_rotate_a(stack_a);
	// 	else
	// 		while ((*stack_a)->value != find_min(*stack_a))
	// 			rotate_a(stack_a);
	// // }