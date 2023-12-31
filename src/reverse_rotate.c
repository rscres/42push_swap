/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:23:30 by renato            #+#    #+#             */
/*   Updated: 2023/10/10 20:37:45 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_dbl_list **stack, int n)
{
	t_dbl_list	*tmp;
	t_dbl_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	tmp = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	head->prev = tmp;
	*stack = tmp;
	if (n == 1)
		write(1, "rra\n", 4);
	else if (n == 2)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_all(t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;
	t_dbl_list	*head;

	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	head = *stack_a;
	tmp = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	head->prev = tmp;
	*stack_a = tmp;
	head = *stack_b;
	tmp = (*stack_b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	head->prev = tmp;
	*stack_b = tmp;
	write(1, "rrr\n", 4);
}
