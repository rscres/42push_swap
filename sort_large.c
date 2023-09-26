/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/26 20:16:22 by rseelaen         ###   ########.fr       */
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
	// printf("piece = %d\n", piece);
	counter = 0;
	cur_piece = size_piece;
	while (*stack_a)
	{
		// printf("counter = %d\n", counter);
		// printf("piece = %d\n", cur_piece);
		if (counter == cur_piece - 1)
			cur_piece += size_piece;
		cheap_high = find_cheap_high(*stack_a, cur_piece);
		cheap_low = find_cheap_low(*stack_a, cur_piece);
		// printf("cheap_high = %d\n", cheap_high);
		// printf("cheap_low = %d\n", cheap_low);
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
			while(!check_sorted(*stack_a))
				algo_3arg(stack_a);
		if (check_sorted(*stack_a))
			break ;
		counter++;
		// print_list(*stack_a);
		// print_list(*stack_b);
	}
	// print_list(*stack_a);
	// print_list(*stack_b);
	while (*stack_b)
	{
		if (!(*stack_a) || ((*stack_b)->index < (*stack_a)->index
				&& (*stack_b)->index > ft_last_index(*stack_a)))
		{
			// ft_printf("here\n");
			push_a(stack_b, stack_a);
		}
		else if ((*stack_b)->index < (*stack_a)->index
			&& (*stack_b)->index < ft_last_index(*stack_a))
		{
			if ((*stack_b)->value < find_min(*stack_a))
				while ((*stack_a)->value != find_min(*stack_a))
					reverse_rotate_a(stack_a);
			else
			{
				while (((*stack_b)->index < (*stack_a)->index
					&& (*stack_b)->index < ft_last_index(*stack_a))
				&& (*stack_a)->value != find_min(*stack_a))
				rotate_a(stack_a);
			}
			push_a(stack_b, stack_a);
		}
		else if ((*stack_b)->index > (*stack_a)->index
			&& (*stack_b)->index < ft_last_index(*stack_a))
		{
			while ((*stack_b)->index > (*stack_a)->index
				&& (*stack_b)->index < ft_last_index(*stack_a))
			{
				rotate_a(stack_a);
			}
			push_a(stack_b, stack_a);
		}
		else if ((*stack_b)->index > (*stack_a)->index
			&& (*stack_b)->index > ft_last_index(*stack_a))
		{
			while ((*stack_b)->index > (*stack_a)->index
				&& (*stack_b)->index > ft_last_index(*stack_a)
				&& (*stack_a)->value != find_min(*stack_a))
			{
				reverse_rotate_a(stack_a);
			}
			push_a(stack_b, stack_a);
		}
		ft_printf("A: ");
		print_list(*stack_a);
		ft_printf("B: ");
		print_list(*stack_b);
	}
}
