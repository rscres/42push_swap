/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/19 17:36:30 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_lst_multiarg(t_dbl_list **stack_a, char **argv, int argc, int init)
{
	int		*num;
	int		i;

	i = init;
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

int	create_lst_1arg(t_dbl_list **stack_a, char *arr)
{
	char	**tab;
	int		*num;
	int		i;

	if (arr[0] == '\0' || arr[0] == ' ' || arr[0] == '\t' || arr[0] == '\n')
		exit (1);
	tab = ft_split(arr, ' ');
	if (!check_int(tab))
		exit (1);
	create_lst_multiarg(stack_a, tab, ft_arrlen(tab), 0);
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
			printf("%d\n", *((int *)temp->content));
			temp = temp->next;
		}
	}
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;
	int			len;

	stack_a = NULL;
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
		len = create_lst_multiarg(&stack_a, argv, argc, 1);
	}
	print_list(stack_a);
	if (check_sorted(stack_a))
		return (0);
	if (len == 2)
		swap_a(&stack_a);
	else if (len == 3)
	{
		while (!check_sorted(stack_a))
			algo_3arg(&stack_a);
	}
	else
	{
		algo_large(&stack_a);
	}
	printf("\n");
	print_list(stack_a);
	ft_dbl_lstclear(&stack_a);
	return (0);
}
