/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:41:27 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 20:27:29 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3elem(t_dbl_list **stack_a)
{
	t_dbl_list	*tmp;

	tmp = NULL;
	tmp = *stack_a;
	if (tmp->value > tmp->next->value
		&& tmp->next->value < tmp->next->next->value
		&& tmp->value > tmp->next->next->value)
		rotate(stack_a, 1);
	else if (tmp->value < tmp->next->value
		&& tmp->next->value > tmp->next->next->value
		&& tmp->value > tmp->next->next->value)
		reverse_rotate(stack_a, 1);
	else if (tmp->value > tmp->next->value)
		swap(stack_a, 1);
	else if (tmp->value < tmp->next->value
		&& tmp->next->value > tmp->next->next->value)
		swap(stack_a, 1);
}
