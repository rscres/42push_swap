/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 13:12:12 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_start_end(t_dbl_list *stack, int mid, t_data *data)
{
	if (!search_piece(stack, mid, data->end))
	{
		data->end = set_end(data->size_piece, stack);
		data->end_counter = 0;
	}
	if (!search_piece(stack, data->start, mid))
	{
		data->start = set_start(data->size_piece, stack);
		data->start_counter = 0;
	}
}

void	move_to_b(t_dbl_list **stack_a, t_dbl_list **stack_b, int mid)
{
	t_data	data;

	data.size_piece = piece_size(stack_a);
	set_start_end(&data, stack_a);
	while (ft_dbl_lstsize(*stack_a) > 3)
	{
		update_start_end(*stack_a, mid, &data);
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
