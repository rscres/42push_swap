/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:49:13 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 21:18:50 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_to_max(t_dbl_list **stack_b)
{
	int			counter;
	int			max;

	counter = 0;
	max = find_max_index(*stack_b);
	if (find_place_index(*stack_b, max) <= ft_dbl_lstsize(*stack_b) / 2)
	{
		while ((*stack_b)->index != max)
		{
			rotate(stack_b, 2);
			counter++;
		}
	}
	else
	{
		while ((*stack_b)->index != max)
		{
			reverse_rotate(stack_b, 2);
			counter++;
		}
	}
	return (counter);
}

static int	check_b_cheaper(t_dbl_list *stack_a, t_dbl_list *stack_b)
{
	int	moves_a;
	int	moves_b;
	int	target;

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

static void	target_not_found(t_dbl_list **stack_a, t_dbl_list **stack_b,
	int mid)
{
	int	target;
	int	place;

	target = find_min(*stack_a);
	place = find_place_index(*stack_a, target);
	if (place < mid)
		while ((*stack_a)->value != target)
			rotate(stack_a, 1);
	else
		while ((*stack_a)->value != target)
			reverse_rotate(stack_a, 1);
	push(stack_b, stack_a, 1);
}

static void	update_data(t_data *data, t_dbl_list **stack_a,
	t_dbl_list **stack_b)
{
	data->target = find_next_larger(*stack_a, (*stack_b)->index);
	data->mid = ft_dbl_lstsize(*stack_a) / 2;
	data->place = find_place_index(*stack_a, data->target);
}

void	move_to_a(t_dbl_list **stack_a, t_dbl_list **stack_b, int mid,
	int piece)
{
	t_data	data;

	data.size = ft_dbl_lstsize(*stack_b);
	data.end = data.size - piece;
	data.mid = mid;
	while (*stack_b)
	{
		if (!search_piece(*stack_b, data.end, data.size))
			data.end -= piece;
		if (check_b_cheaper(*stack_a, *stack_b) || (*stack_b)->index < data.end)
			get_to_max(stack_b);
		update_data(&data, stack_a, stack_b);
		if (data.target == -1)
			target_not_found(stack_a, stack_b, data.mid);
		else
		{
			if (data.place <= data.mid)
				while ((*stack_a)->index != data.target)
					rotate(stack_a, 1);
			else
				while ((*stack_a)->index != data.target)
					reverse_rotate(stack_a, 1);
			push(stack_b, stack_a, 1);
		}
	}
}
