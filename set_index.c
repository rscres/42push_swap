/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:37:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/25 22:00:30 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_dbl_list *stack)
{
	t_dbl_list	*tmp;
	int			cur;
	int			min;

	tmp = stack;
	while (tmp->index != -1)
		tmp = tmp->next;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min && tmp->index == -1)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	set_index(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;
	int			i;
	int			lst_size;
	int			min;

	i = 0;
	lst_size = ft_dbl_lstsize(*stack_a);
	while (i < lst_size)
	{
		tmp = *stack_a;
		min = find_min_index(*stack_a);
		printf("min: %d\n", min);
		while (tmp)
		{
			printf("%d: %d\n", tmp->index, tmp->value);
			if (tmp->value == min)
			{
				tmp->index = i;
				
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (1);
}
