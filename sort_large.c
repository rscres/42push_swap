/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/09 22:30:33 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_start_end(t_data *data, t_dbl_list **stack_a)
{
	data->start = set_start(data->size_piece, *stack_a);
	data->end = set_end(data->size_piece, *stack_a);
	data->start_counter = 0;
	data->end_counter = 0;
}

void	move_to_b(t_dbl_list **stack_a, t_dbl_list **stack_b, int mid)
{
	t_data	data;

	data.size_piece = piece_size(stack_a);
	set_start_end(&data, stack_a);
	while (ft_dbl_lstsize(*stack_a) > 3)
	{
		if (!search_piece(*stack_a, mid, data.end))
		{
			data.end = set_end(data.size_piece, *stack_a);
			data.end_counter = 0;
		}
		if (!search_piece(*stack_a, data.start, mid))
		{
			data.start = set_start(data.size_piece, *stack_a);
			data.start_counter = 0;
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

int	get_to_max(t_dbl_list **stack_b, int mid)
{
	int			counter;
	int			max;
	static int	first;
	static int	piece;

	counter = 0;
	if (!piece)
		piece = piece_size(stack_b);
	max = find_max_index(*stack_b);
	if (find_place_index(*stack_b, max) <= ft_dbl_lstsize(*stack_b) / 2)
	{
		while ((*stack_b)->index != max)
		{
			rotate_b(stack_b);
			counter++;
		}
	}
	else
	{
		while ((*stack_b)->index != max)
		{
			reverse_rotate_b(stack_b);
			counter++;
		}
	}
	return (counter);
}

int	check_b_cheaper(t_dbl_list *stack_a, t_dbl_list *stack_b)
{
	int	moves_a;
	int	moves_b;
	int	target;
	static int	piece;

	target = find_next_larger(stack_a, stack_b->index);
	if (target == -1)
	{	
		if (find_min_index(stack_a) <= find_max_index(stack_a))
			target = find_min_index(stack_a);
		else
			target = find_max_index(stack_a);
	}
	moves_a = find_place_index(stack_a, target);
	if (moves_a > ft_dbl_lstsize(stack_a) / 2)
		moves_a = (ft_dbl_lstsize(stack_a) - moves_a) + 1;
	target = find_max_index(stack_b);
	moves_b = find_place_index(stack_b, target);
	if (moves_b > ft_dbl_lstsize(stack_b) / 2)
		moves_b = (ft_dbl_lstsize(stack_b) - moves_b) + 1;
	if (moves_a == -1 || moves_a < moves_b)
		return (0);
	return (1);
}

void	move_to_a(t_dbl_list **stack_a, t_dbl_list **stack_b, int mid, int piece)
{
	int	target;
	int	place;
	int	end;
	int	size;

	size = ft_dbl_lstsize(*stack_b);
	end = size - piece;
	while (*stack_b)
	{
		if (!search_piece(*stack_b, end, size))
			end -= piece;
		if (check_b_cheaper(*stack_a, *stack_b) || (*stack_b)->index < end)
			get_to_max(stack_b, mid);
		target = find_next_larger(*stack_a, (*stack_b)->index);
		mid = ft_dbl_lstsize(*stack_a) / 2;
		place = find_place_index(*stack_a, target);
		if (target == -1)
		{
			target = find_min(*stack_a);
			if (place < mid)
				while ((*stack_a)->value != target)
					rotate_a(stack_a);
			else
				while ((*stack_a)->value != target)
					reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
		else
		{
			if (place <= mid)
				while ((*stack_a)->index != target)
					rotate_a(stack_a);
			else
				while ((*stack_a)->index != target)
					reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
	}
}

void	sort_large(t_dbl_list **stack_a)
{
	t_dbl_list	**stack_b;
	int			mid;
	int			piece;

	stack_b = malloc(sizeof(t_dbl_list *));
	*stack_b = NULL;
	piece = piece_size(stack_a);
	mid = ft_dbl_lstsize(*stack_a) / 2;
	move_to_b(stack_a, stack_b, mid);
	sort_3elem(stack_a);
	move_to_a(stack_a, stack_b, mid, piece);
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
