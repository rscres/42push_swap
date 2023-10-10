/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:22:58 by renato            #+#    #+#             */
/*   Updated: 2023/10/10 20:38:07 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_dbl_list **stack_src, t_dbl_list **stack_dest, int n)
{
	t_dbl_list	*tmp;

	if (!stack_src)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	tmp->next = *stack_dest;
	if (*stack_dest)
		(*stack_dest)->prev = tmp;
	*stack_dest = tmp;
	if (n == 1)
		write(1, "pa\n", 3);
	else if (n == 2)
		write(1, "pb\n", 3);
}
