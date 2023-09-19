/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:55:46 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/19 15:05:20 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	(*stack_a)->next->prev = tmp;
	tmp->next = (*stack_a)->next;
	tmp->prev = *stack_a;
	(*stack_a)->next = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	(*stack_b)->next->prev = tmp;
	tmp->next = (*stack_b)->next;
	tmp->prev = *stack_b;
	(*stack_b)->next = tmp;
	write(1, "sa\n", 3);
}

void	swap_all(t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	(*stack_a)->next->prev = tmp;
	tmp->next = (*stack_a)->next;
	tmp->prev = *stack_a;
	(*stack_a)->next = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	(*stack_b)->next->prev = tmp;
	tmp->next = (*stack_b)->next;
	tmp->prev = *stack_b;
	(*stack_b)->next = tmp;
	write(1, "ss\n", 3);
}
