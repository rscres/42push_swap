/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/04 17:22:24 by rseelaen         ###   ########.fr       */
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

int	find_next_smaller(t_dbl_list *stack, int index)
{
	int	next;

	next = -1;
	while (stack)
	{
		if (stack->index < index && next == -1)
		{
			next = stack->index;
		}
		if ((stack->index < index) && (stack->index > next))
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

void	set_start_end(t_data *data, t_dbl_list **stack_a)
{
	data->start = set_start(data->size_piece, *stack_a);
	data->end = set_end(data->size_piece, *stack_a);
	data->start_counter = 0;
	data->end_counter = 0;
}

void	move_to_a(t_dbl_list **stack_a, t_dbl_list **stack_b, int mid)
{
	t_data	data;

	data.size_piece = piece_size(stack_a);
	set_start_end(&data, stack_a);
	while (ft_dbl_lstsize(*stack_a) > 3)
	{
		if (!search_piece(*stack_a, data.start, data.end))
		{
			set_start_end(&data, stack_a);
		}
		if ((*stack_a)->index >= data.start && (*stack_a)->index <= data.end)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->index < mid)
			{
				data.start_counter++;
				rotate_b(stack_b);
			}
			else
				data.end_counter++;
		}
		else
			rotate_a(stack_a);
	}
}

void	algo_large(t_dbl_list **stack_a)
{
	t_dbl_list	**stack_b;
	int			mid;

	stack_b = malloc(sizeof(t_dbl_list *));
	*stack_b = NULL;
	mid = ft_dbl_lstsize(*stack_a) / 2;
	move_to_a(stack_a, stack_b, mid);
	algo_3arg(stack_a);
	int	target;
	while (*stack_b)
	{
		target = find_next_larger(*stack_a, (*stack_b)->index);
		mid = ft_dbl_lstsize(*stack_a) / 2;
		if (target == -1)
		{
			target = find_min(*stack_a);
			if (find_place_index(*stack_a, target)
				< mid)
				while ((*stack_a)->value != target)
					rotate_a(stack_a);
			else
				while ((*stack_a)->value != target)
					reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		else if (find_place_index(*stack_a, target)
			<= mid)
		{
			while ((*stack_a)->index != target)
				rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		else if (find_place_index(*stack_a, target)
			> mid)
		{
			while ((*stack_a)->index != target)
				reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		target = 0;
	}
	if (!check_sorted(*stack_a))
	{
		mid = ft_dbl_lstsize(*stack_a) / 2;
		if (find_place_index(*stack_a, 0) <= mid)
			while ((*stack_a)->index != 0)
				rotate_a(stack_a);
		else
			while ((*stack_a)->index != 0)
				reverse_rotate_a(stack_a);
	}
	free(stack_b);
}
