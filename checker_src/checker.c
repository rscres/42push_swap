/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:20 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 22:23:56 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

int	check_move(char *move, t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		swap(stack_a, 0);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap(stack_b, 0);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		swap_all(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(stack_a, 0);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(stack_b, 0);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rotate_all(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		reverse_rotate(stack_a, 0);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		reverse_rotate(stack_b, 0);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		reverse_rotate_all(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		push(stack_b, stack_a, 0);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push(stack_a, stack_b, 0);
	else
	{
		ft_error(stack_a);
	}
	return (0);
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
	t_dbl_list	*stack_b;
	char		*move;

	stack_a = NULL;
	if (argc < 2)
		exit (1);
	input_checker(&stack_a, argc, argv);
	move = argv[1];
	stack_b = NULL;
	while(move)
	{
		move = get_next_line(0);
		check_move(move, &stack_a, &stack_b);
		if (check_sorted(stack_a) && !stack_b)
			break ;
	}
	free(move);
	if (!check_sorted(stack_a) || stack_b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}
