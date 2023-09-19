/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:24:52 by renato            #+#    #+#             */
/*   Updated: 2023/09/19 00:49:01 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;
	t_dbl_list	*cur;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	cur = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	tmp->prev = cur;
	tmp->next = NULL;
	cur->next = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;
	t_dbl_list	*cur;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	cur = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	tmp->prev = cur;
	tmp->next = NULL;
	cur->next = tmp;
	write(1, "rb\n", 3);
}

void	rotate_all(t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;
	t_dbl_list	*cur;

    if (*stack_a == NULL || (*stack_a)->next == NULL
        || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_a;
	cur = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	tmp->prev = cur;
	tmp->next = NULL;
	cur->next = tmp;
	tmp = *stack_b;
	cur = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	tmp->prev = cur;
	tmp->next = NULL;
	cur->next = tmp;
	write(1, "rr\n", 3);
}
