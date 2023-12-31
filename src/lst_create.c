/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:29:50 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 21:19:14 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_lst_multiarg(t_dbl_list **stack_a, char **argv, int argc, int init)
{
	int		num;
	int		i;

	i = init;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (stack_a == NULL)
		{
			*stack_a = ft_dbl_lstnew(num);
		}
		else
		{
			ft_dbl_lstadd_back(stack_a, ft_dbl_lstnew(num));
		}
		i++;
	}
	return (i - 1);
}

int	create_lst_1arg(t_dbl_list **stack_a, char *arr)
{
	char	**tab;
	int		i;

	if (arr[0] == '\0' || arr[0] == ' ' || arr[0] == '\t' || arr[0] == '\n')
		ft_error(stack_a);
	tab = ft_split(arr, ' ');
	if (!check_int(tab))
	{
		free_tab(tab);
		ft_error(stack_a);
	}
	create_lst_multiarg(stack_a, tab, ft_arrlen(tab), 0);
	i = free_tab(tab);
	return (i);
}
