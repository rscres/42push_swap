/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:41:27 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/28 13:39:16 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3arg(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;

	tmp = NULL;
	tmp = *stack_a;
	if (tmp->value > tmp->next->value
		&& tmp->next->value < tmp->next->next->value
		&& tmp->value > tmp->next->next->value)
		rotate_a(stack_a);
	else if (tmp->value < tmp->next->value
		&& tmp->next->value > tmp->next->next->value
		&& tmp->value > tmp->next->next->value)
		reverse_rotate_a(stack_a);
	else if (tmp->value > tmp->next->value)
		swap_a(stack_a);
	else if (tmp->value < tmp->next->value
		&& tmp->next->value > tmp->next->next->value)
		swap_a(stack_a);
}
