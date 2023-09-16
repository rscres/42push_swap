/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 21:25:49 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	parse(char **argv, t_dbl_list *stack_a)
{
	int	i;
	int	j;

	while (argv[1])
	{
		i = 0;
		j = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
			{
				if (j == 0)
				{
					stack_a->content = &(ft_atoi(argv[1]));
					stack_a->next = malloc(sizeof(t_dbl_list));
					stack_a->next->prev = stack_a;
					stack_a = stack_a->next;
					j++;
				}
				else
				{
					stack_a->content = &(ft_atoi(argv[1] + i + 1));
					stack_a->next = malloc(sizeof(t_dbl_list));
					stack_a->next->prev = stack_a;
					stack_a = stack_a->next;
				}
			}
			i++;
		}
		argv++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{	
		parse(argv, stack_a);
		while (stack_a)
		{
			printf("%d\n", (int)stack_a->content);
			stack_a = stack_a->next;
		}
	}
	if (argc > 2)
	{
		ft_printf("argc > 2\n");
	}
	return (0);
}
