/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/18 00:11:13 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	create_lst_1arg(t_dbl_list **stack_a, char *arr)
{
	char	**tab;
	int		*num;
	int 	i;

	tab = ft_split(arr, ' ');
	i = 0;
	while (tab[i])
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(tab[i]);
		if (stack_a == NULL)
			*stack_a = ft_dbl_lstnew(num);
		else
			ft_dbl_lstadd_back(stack_a, ft_dbl_lstnew(num));
		i++;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

int	create_lst_multiarg(t_dbl_list **stack_a, char **argv, int argc)
{
	int		*num;
	int 	i;

	i = 1;
	while (i < argc)
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(argv[i]);
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
	return (1);
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{	
		create_lst_1arg(&stack_a, argv[1]);
	}
	if (argc > 2)
	{
		create_lst_multiarg(&stack_a, argv, argc);
	}
	t_dbl_list *temp;
	temp = NULL;
	if (stack_a)
	{
		temp = stack_a;
		while (temp)
		{
			printf("%d\n", *((int *)temp->content));
			temp = temp->next;
		}
	}
	temp = NULL;
	rotate_a(&stack_a);
	swap_a(&stack_a);
	temp = stack_a;
	int i = 0;
	while (temp)
	{
		printf("%d\n", *((int *)temp->content));
		temp = temp->next;
	}
	ft_dbl_lstclear(&stack_a);
	return (0);
}
