/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:51:36 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 13:03:26 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_dbl_list *stack_a)
{
	t_dbl_list	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
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
			if (tmp->value == stack_a->value)
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

int	input_checker(t_dbl_list **stack_a, int argc, char **argv)
{
	int	len;

	if (argc < 2)
		ft_error(stack_a);
	if (argc == 2)
		len = create_lst_1arg(stack_a, argv[1]);
	if (argc > 2)
	{
		if (!check_int((argv + 1)))
			ft_error(stack_a);
		len = create_lst_multiarg(stack_a, argv, argc, 1);
	}
	if (check_doubles(*stack_a))
		ft_error(stack_a);
	if (check_sorted(*stack_a))
	{
		ft_dbl_lstclear(stack_a);
		exit(0);
	}
	return (len);
}
