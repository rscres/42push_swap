/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 20:44:09 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (len == 2)
		swap(&stack_a, 1);
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
	ft_dbl_lstclear(&stack_a);
	return (0);
}
