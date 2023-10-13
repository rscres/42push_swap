/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:29:45 by renato            #+#    #+#             */
/*   Updated: 2023/10/13 13:50:29 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_start_end(t_data *data, t_dbl_list **stack_a)
{
	data->start = set_start(data->size_piece, *stack_a);
	data->end = set_end(data->size_piece, *stack_a);
}
