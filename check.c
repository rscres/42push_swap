/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:51:36 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/18 15:23:37 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_sorted(t_dbl_list *stack_a)
{
	t_dbl_list	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_doubles(t_dbl_list *stack_a)
{
	t_dbl_list	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (*((int *)tmp->content) == *((int *)stack_a->content))
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
