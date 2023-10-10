/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:20 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 20:37:18 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_move(char *move, t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	if (move == "sa\n")
		swap(stack_a, 0);
	else if (move == "sb\n")
		swap(stack_b, 0);
	else if (move == "ss\n")
		swap_all(stack_a, stack_b);
	else if (move == "ra\n")
		rotate(stack_a, 0);
	else if (move == "rb\n")
		rotate(stack_b, 0);
	else if (move == "rr\n")
		rotate_all(stack_a, stack_b);
	else if (move == "rra\n")
		reverse_rotate(stack_a, 0);
	else if (move == "rrb\n")
		reverse_rotate(stack_b, 0);
	else if (move == "rrr\n")
		reverse_rotate_all(stack_a, stack_b);
	else if (move == "pa\n")
		push(stack_b, stack_a, 0);
	else if (move == "pb\n")
		push(stack_a, stack_b, 0);
	else
	{
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_dbl_list	**stack_a;
	t_dbl_list	**stack_b;
	int			i;
	char		*move;

	if (argc < 2)
		exit (1);
	if (argc == 2)
	{
		create_lst_1arg(stack_a, argv[1]);
	}
	if (argc > 2)
	{
		create_lst_multiarg(stack_a, argv, argc, 1);
	}
	i = 0;
	move = get_next_line(0);
	while(move)
	{
		valid_move(move, stack_a, stack_b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (!check_sorted(*stack_a) || stack_b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}
