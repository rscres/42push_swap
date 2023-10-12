/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:25:55 by renato            #+#    #+#             */
/*   Updated: 2023/10/09 22:29:17 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
