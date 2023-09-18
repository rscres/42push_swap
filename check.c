/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:51:36 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/18 18:27:31 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	check_int(char **arg)
{
	int			i;
	int			j;
	long int	num;

	i = 0;
	while (arg[i])
	{
		j = 0;
		num = ft_atol(arg[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]) && arg[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
