/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/21 16:28:26 by rseelaen         ###   ########.fr       */
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
	int		*num;
	int		i;

	if (arr[0] == '\0' || arr[0] == ' ' || arr[0] == '\t' || arr[0] == '\n')
		ft_error(0);
	tab = ft_split(arr, ' ');
	if (!check_int(tab))
	{
		free_tab(tab);
		ft_error(2);
	}
	create_lst_multiarg(stack_a, tab, ft_arrlen(tab), 0);
	i = free_tab(tab);
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

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;
	int			len;

	stack_a = NULL;
	if (argc < 2)
		ft_error(1);
	if (argc == 2)
		len = create_lst_1arg(&stack_a, argv[1]);
	if (argc > 2)
	{
		if (!check_int((argv + 1)))
			ft_error(2);
		len = create_lst_multiarg(&stack_a, argv, argc, 1);
	}
	if (check_doubles(stack_a))
		ft_error(3);
	// print_list(stack_a);
	if (check_sorted(stack_a))
		return (0);
	if (len == 2)
		swap_a(&stack_a);
	else if (len == 3)
	{
		while (!check_sorted(stack_a))
			algo_3arg(&stack_a);
	}
	else if (len <= 5)
	{
		algo_5elem(&stack_a);
	}
	// else
	// {
	// 	algo_large(&stack_a);
	// }
	// printf("\n");
	// print_list(stack_a);
	ft_dbl_lstclear(&stack_a);
	return (0);
}
