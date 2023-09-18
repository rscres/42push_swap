/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:55:46 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/18 18:32:31 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "sa\n", 3);
}

void	swap_all(t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	t_dbl_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL
		|| (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "ss\n", 3);
}

void	rotate_a(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;
	t_dbl_list	*cur;


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

void	reverse_rotate_a(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;
	t_dbl_list	*head;

	head = *stack_a;
	tmp = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	head->prev = tmp;
	stack_a = &tmp;
	printf("num: %d\nnext: %d\n\n", *((int *)tmp->content), *((int *)tmp->next->content));
}
