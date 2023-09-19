/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/19 00:15:41 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_lst_1arg(t_dbl_list **stack_a, char *arr)
{
	char	**tab;
	int		*num;
	int		i;

	tab = ft_split(arr, ' ');
	if (!check_int(tab))
		exit (1);
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
	return (i);
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
	return (i - 1);
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
			printf("%d\n", *((int *)temp->content));
			temp = temp->next;
		}
	}
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;
	t_dbl_list	*stack_b;
	int			len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{	
		len = create_lst_1arg(&stack_a, argv[1]);
	}
	if (argc > 2)
	{
		if (!check_int((argv + 1)))
			exit (1);
		len = create_lst_multiarg(&stack_a, argv, argc);
	}
	print_list(stack_a);
	if (check_sorted(stack_a))
		return (0);
	if (len == 2)	
		swap_a(&stack_a);
	if (len == 3)
	{
		printf("len == 3\n");
	}
	print_list(stack_a);
	ft_dbl_lstclear(&stack_a);
	return (0);
}
