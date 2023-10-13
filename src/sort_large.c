/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/13 13:48:31 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_start_end(t_dbl_list *stack, int mid, t_data *data)
{
	if (!search_piece(stack, mid, data->end))
	{
		data->end = set_end(data->size_piece, stack);
	}
	if (!search_piece(stack, data->start, mid))
	{
		data->start = set_start(data->size_piece, stack);
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
			push(stack_a, stack_b, 2);
			if ((*stack_b)->index < mid)
				rotate(stack_b, 2);
		}
		else
			rotate(stack_a, 1);
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
				rotate(stack_a, 1);
		else
			while ((*stack_a)->index != 0)
				reverse_rotate(stack_a, 1);
	}
	free(stack_b);
}
