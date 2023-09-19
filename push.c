/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:22:58 by renato            #+#    #+#             */
/*   Updated: 2023/09/19 17:38:21 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;

	if (!stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = tmp;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	push_a(t_dbl_list **stack_b, t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;

	if (!stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = tmp;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}
