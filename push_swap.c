/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/05 12:10:56 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (i);
}

void	print_list(t_dbl_list *list)
{
	t_dbl_list	*temp;

	temp = NULL;
	if (list)
	{
		temp = list;
		while (temp)
		{
			ft_printf("%d ", temp->value);
			temp = temp->next;
		}
	}
	ft_printf("\n");
}

void	print_index(t_dbl_list *list)
{
	t_dbl_list	*temp;

	temp = NULL;
	if (list)
	{
		temp = list;
		while (temp)
		{
			ft_printf("%d ", temp->index);
			temp = temp->next;
		}
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;
	int			len;

	stack_a = NULL;
	len = input_checker(&stack_a, argc, argv);
	set_index(&stack_a);
	// print_list(stack_a);
	// print_index(stack_a);
	if (len == 2)
		swap_a(&stack_a);
	else if (len == 3)
	{
		while (!check_sorted(stack_a))
			sort_3elem(&stack_a);
	}
	else if (len <= 5)
	{
		sort_5elem(&stack_a);
	}
	else
	{
		sort_large(&stack_a);
	}
	// printf("\n");
	// print_list(stack_a);
	ft_dbl_lstclear(&stack_a);
	return (0);
}
