/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:41:27 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/19 15:03:46 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3arg(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;

	tmp = NULL;
	tmp = *stack_a;
	if (*(int *)tmp->content > *(int *)tmp->next->content
		&& *(int *)tmp->next->content < *(int *)tmp->next->next->content
		&& *(int *)tmp->content > *(int *)tmp->next->next->content)
		rotate_a(stack_a);
	else if (*(int *)tmp->content < *(int *)tmp->next->content
		&& *(int *)tmp->next->content > *(int *)tmp->next->next->content
		&& *(int *)tmp->content > *(int *)tmp->next->next->content)
		reverse_rotate_a(stack_a);
	else if (*(int *)tmp->content > *(int *)tmp->next->content)
		swap_a(stack_a);
	else if (*(int *)tmp->content < *(int *)tmp->next->content
		&& *(int *)tmp->next->content > *(int *)tmp->next->next->content)
		swap_a(stack_a);
}
