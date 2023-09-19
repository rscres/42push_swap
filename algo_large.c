/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:14 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/19 18:05:32 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_dbl_list *stack)
{
	int			min;
	t_dbl_list	*tmp;

	tmp = stack;
	min = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_dbl_list *stack)
{
	int			max;
	t_dbl_list	*tmp;

	tmp = stack;
	max = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
			max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

void	algo_large(t_dbl_list **stack_a)
{
	t_dbl_list	**stack_b;
	int			b_min;
	int			b_max;

	stack_b = malloc(sizeof(t_dbl_list *));
	*stack_b = NULL;
	b_min = 0;
	b_max = 0;
	while (ft_dbl_lstsize(*stack_b) < 2)
		push_b(stack_a, stack_b);
	b_min = find_min(*stack_b);
	b_max = find_max(*stack_b);
	while (ft_dbl_lstsize(*stack_a) > 3)
	{
		
	}
	print_list(*stack_a);
	printf("stack_b\n");
	print_list(*stack_b);
}
