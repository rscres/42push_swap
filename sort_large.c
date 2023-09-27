/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/27 18:30:51 by rseelaen         ###   ########.fr       */
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

int	piece_size(t_dbl_list **stack)
{
	int	size;

	size = ft_dbl_lstsize(*stack);
	if (size <= 100)
		return (size / 5);
	else if (size <= 500)
		return (size / 11);
	else
		return (size / 21);
}

int	find_cheap_high(t_dbl_list *stack, int piece)
{
	int	mid;
	int	i;

	mid = ft_dbl_lstsize(stack) / 2;
	i = 0;
	while (i < mid)
	{
		if (stack->index < piece)
			break ;
		stack = stack->next;
		i++;
	}
	// printf("high = %d:%d\n", stack->index, stack->value);
	return (i);
}

int	find_cheap_low(t_dbl_list *stack, int piece)
{
	int	mid;
	int	i;
	t_dbl_list *tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	mid = ft_dbl_lstsize(stack) / 2;
	i = 1;
	while (i <= mid)
	{
		if (tmp->index < piece)
			break ;
		tmp = tmp->prev;
		i++;
	}
	// printf("low = %d:%d\n", tmp->index, tmp->value);
	return (i);
}

int	ft_last_index(t_dbl_list *stack)
{
	t_dbl_list	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->index);
}

int	find_place_index(t_dbl_list *stack, int index)
{
	int	i;

	i = -1;
	while (stack->index != index)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_next_larger(t_dbl_list *stack, int index)
{
	int	next;

	next = -1;
	while (stack)
	{
		if (stack->index > index && next == -1)
		{
			next = stack->index;
		}
		if ((stack->index > index) && (stack->index < next))
		{
			next = stack->index;
		}
		stack = stack->next;
	}
	return (next);
}

void	algo_large(t_dbl_list **stack_a)
{
	t_dbl_list	**stack_b;
	int			size_piece;
	int			cur_piece;
	int			cheap_high;
	int			cheap_low;
	int			counter;

	stack_b = malloc(sizeof(t_dbl_list *));
	*stack_b = NULL;
	size_piece = piece_size(stack_a);
	counter = 0;
	cur_piece = size_piece;
	while (*stack_a)
	{
		if (counter == cur_piece - 1)
			cur_piece += size_piece;
		cheap_high = find_cheap_high(*stack_a, cur_piece);
		cheap_low = find_cheap_low(*stack_a, cur_piece);
		if (cheap_high <= cheap_low)
		{
			while (cheap_high--)
				rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		else
		{
			while (cheap_low--)
				reverse_rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		if (ft_dbl_lstsize(*stack_a) <= 3)
			while (!check_sorted(*stack_a))
				algo_3arg(stack_a);
		if (check_sorted(*stack_a))
			break ;
		counter++;
		ft_printf("A: ");
		print_list(*stack_a);
		ft_printf("B: ");
		print_list(*stack_b);
	}
	// ft_printf("A: ");
	// print_list(*stack_a);
	// ft_printf("B: ");
	// print_list(*stack_b);
	int	target;
	while (*stack_b)
	{
		if (!stack_a)
			push_a(stack_b, stack_a);
		target = find_next_larger(*stack_a, (*stack_b)->index);
		if (target == -1)
		{
			target = find_min(*stack_a);
			if (find_place_index(*stack_a, target)
				< ft_dbl_lstsize(*stack_a) / 2)
				while ((*stack_a)->value != target)
					rotate_a(stack_a);
			else
				while ((*stack_a)->value != target)
					reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		else if (find_place_index(*stack_a, target)
			< ft_dbl_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->index != target)
				rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		else if (find_place_index(*stack_a, target)
			>= ft_dbl_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->index != target)
				reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		target = 0;
		ft_printf("A: ");
		print_list(*stack_a);
		ft_printf("B: ");
		print_list(*stack_b);
	}
	// ft_printf("A: ");
	// print_list(*stack_a);
	// ft_printf("B: ");
	// print_list(*stack_b);
	if (!check_sorted(*stack_a))
	{
		if (find_place_index(*stack_a, 0) < ft_dbl_lstsize(*stack_a) / 2)
			while ((*stack_a)->index != 0)
				rotate_a(stack_a);
		else
			while ((*stack_a)->index != 0)
				reverse_rotate_a(stack_a);
	}
	free(stack_b);
}
