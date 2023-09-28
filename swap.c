/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:55:46 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/28 13:38:45 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_dbl_list **stack_a)
{
	t_dbl_list	*first;
	t_dbl_list	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	first->prev = NULL;
	second->prev = NULL;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	if (second->next != NULL)
		second->next->prev = second;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	swap_b(t_dbl_list **stack_b)
{
	t_dbl_list	*first;
	t_dbl_list	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	first->prev = NULL;
	second->prev = NULL;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	if (second->next != NULL)
		second->next->prev = second;
	*stack_b = second;
	write(1, "sb\n", 3);
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
