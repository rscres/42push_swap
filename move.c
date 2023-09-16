/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:55:46 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 21:27:02 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_dbl_list *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = *((int *)stack_a->content);
	stack_a->content = stack_a->next->content;
	stack_a->next->content = &tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_dbl_list *stack_b)
{
	int	tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	tmp = *((int *)stack_b->content);
	stack_b->content = stack_b->next->content;
	stack_b->next->content = &tmp;
	write(1, "sa\n", 3);
}

void	swap_all(t_dbl_list *stack_a, t_dbl_list *stack_b)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL || stack_b == NULL
		|| stack_b->next == NULL)
		return ;
	tmp = *((int *)stack_a->content);
	stack_a->content = stack_a->next->content;
	stack_a->next->content = &tmp;
	tmp = *((int *)stack_b->content);
	stack_b->content = stack_b->next->content;
	stack_b->next->content = &tmp;
	write(1, "ss\n", 3);
}

void	rotate_a(t_dbl_list *stack_a)
{
	t_dbl_list	*tmp;

	tmp = stack_a;
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	stack_a->next = tmp;
	write(1, "ra\n", 3);
}