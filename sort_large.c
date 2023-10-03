/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/03 17:18:11 by rseelaen         ###   ########.fr       */
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
	if (size <= 10)
		return (size / 5);
	if (size <= 100)
		return (size / 8);
	else if (size <= 500)
		return (size / 14);
	else
		return (size / 21);
}

int	find_cheap_high(t_dbl_list *stack, int start)
{
	int	mid;
	int	i;

	mid = ft_dbl_lstsize(stack) / 2;
	i = 0;
	while (stack && i < mid)
	{
		if (stack->index >= start && stack->index <= mid)
			break ;
		stack = stack->next;
		i++;
	}
	// printf("high index= %d\n", stack->index);
	return (i);
}

int	find_cheap_low(t_dbl_list *stack, int end)
{
	int			mid;
	int			i;
	t_dbl_list	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	mid = ft_dbl_lstsize(stack) / 2;
	i = 1;
	while (stack && i <= mid)
	{
		if (tmp->index <= end && tmp->index > mid)
			break ;
		tmp = tmp->prev;
		i++;
	}
	// printf("low index= %d\n", tmp->index);
	return (i);
}

int	ft_last_index(t_dbl_list *stack)
{
	t_dbl_list	*tmp;

	tmp = stack;
	while (stack && tmp->next)
		tmp = tmp->next;
	return (tmp->index);
}

int	find_place_index(t_dbl_list *stack, int index)
{
	int	i;

	i = -1;
	while (stack && stack->index != index)
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

int	set_start(int size_piece, t_dbl_list *stack_a)
{
	static int	times;
	static int	mid;
	int			start;

	if (times == 0)
		times = 1;
	if (!mid)
		mid = ft_dbl_lstsize(stack_a) / 2;
	start = mid - (size_piece * times);
	if (start < 0)
		start = 0;
	times++;
	return (start);
}

int	set_end(int size_piece, t_dbl_list *stack_a)
{
	static int	times;
	static int	mid;
	static int	size;
	int			end;

	if (times == 0)
		times = 1;
	if (!size)
		size = ft_dbl_lstsize(stack_a);
	if (!mid)
		mid = size / 2;
	end = mid + (size_piece * times);
	if (end > size)
		end = size;
	times++;
	return (end);
}

int	search_piece(t_dbl_list *stack, int start, int end)
{
	while (stack)
	{
		if (stack->index >= start && stack->index <= end)
			return (1);
		stack = stack->next;
	}
	return (0);
}



void	algo_large(t_dbl_list **stack_a)
{
	t_dbl_list	**stack_b;
	int			size_piece;
	int			cheap_high;
	int			cheap_low;
	int			counter;
	int			start;
	int			end;
	int 		mid = ft_dbl_lstsize(*stack_a) / 2;
	int			start_counter;
	int			end_counter;

	stack_b = malloc(sizeof(t_dbl_list *));
	*stack_b = NULL;
	size_piece = piece_size(stack_a);
	counter = 0;
	start = set_start(size_piece, *stack_a);
	end = set_end(size_piece, *stack_a);
	// printf("start = %d\n", start);
	// printf("end = %d\n", end);
	start_counter = 0;
	end_counter = 0;
	// print_list(*stack_a);
	while (ft_dbl_lstsize(*stack_a) > 3)
	{
		if (!search_piece(*stack_a, start, end))
		{
			start = set_start(size_piece, *stack_a);
			end = set_end(size_piece, *stack_a);
			start_counter = 0;
			end_counter = 0;
		}
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->index < mid)
			{
				start_counter++;
				if ((*stack_b))
					rotate_b(stack_b);
			}
			else
				end_counter++;
		}
		else
		{
			rotate_a(stack_a);
		}
	}
	algo_3arg(stack_a);
	// print_list(*stack_a);
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
	}
	if (*stack_a && (*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
	if (!check_sorted(*stack_a))
	{
		if (find_place_index(*stack_a, 0) <= ft_dbl_lstsize(*stack_a) / 2)
			while ((*stack_a)->index != 0)
				rotate_a(stack_a);
		else
			while ((*stack_a)->index != 0)
				reverse_rotate_a(stack_a);
	}
	// print_list(*stack_a);
	free(stack_b);
}

// // if (start_counter == start)
// // {
// // 	start = set_start(size_piece, *stack_a);
// // 	start_counter = 0;
// // }
// // if (end_counter == end)
// // {
// // 	end = set_end(size_piece, *stack_a);
// // 	end_counter = 0;
// // }
// if (counter == size_piece)
// {
// 	start = set_start(size_piece, *stack_a);
// 	end = set_end(size_piece, *stack_a);
// 	counter = 0;
// }
// cheap_high = find_cheap_high(*stack_a, start);
// cheap_low = find_cheap_low(*stack_a, end);
// // printf("cheap_high = %d\n", cheap_high);
// // printf("cheap_low = %d\n", cheap_low);
// if (cheap_high > cheap_low)
// {
// 	if (cheap_low < mid)
// 		start_counter++;
// 	else
// 		end_counter++;
// 	while (cheap_low--)
// 		reverse_rotate_a(stack_a);
// 	push_b(stack_a, stack_b);
// 	if ((*stack_b)->index < mid)
// 		rotate_b(stack_b);
// }
// else
// {
// 	if (cheap_low < mid)
// 		start_counter++;
// 	else
// 		end_counter++;
// 	// printf("cheap_high > cheap_low\n");
// 	while (cheap_high--)
// 		rotate_a(stack_a);
// 	push_b(stack_a, stack_b);
// 	if ((*stack_b)->index < mid)
// 		rotate_b(stack_b);

// }
// if (check_sorted(*stack_a))
// 	break ;
// counter++;