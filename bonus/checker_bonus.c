/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:20 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/12 14:26:12 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_move(char *move, t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	if (!ft_strncmp(move, "sa\n", 3))
		swap(stack_a, 0);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap(stack_b, 0);
	else if (!ft_strncmp(move, "ss\n", 3))
		swap_all(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra\n", 3))
		rotate(stack_a, 0);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate(stack_b, 0);
	else if (!ft_strncmp(move, "rr\n", 3))
		rotate_all(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra\n", 4))
		reverse_rotate(stack_a, 0);
	else if (!ft_strncmp(move, "rrb\n", 4))
		reverse_rotate(stack_b, 0);
	else if (!ft_strncmp(move, "rrr\n", 4))
		reverse_rotate_all(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa\n", 3))
		push(stack_b, stack_a, 0);
	else if (!ft_strncmp(move, "pb\n", 3))
		push(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

void	clear_lists(t_dbl_list **stack_a, t_dbl_list **stack_b)
{
	if (stack_b)
		ft_dbl_lstclear(stack_b);
	if (stack_a)
		ft_dbl_lstclear(stack_a);
}

void	check_output(t_dbl_list *stack_a, t_dbl_list *stack_b)
{
	if (stack_a && check_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;
	t_dbl_list	*stack_b;
	char		*move;

	stack_a = NULL;
	input_checker(&stack_a, argc, argv, 0);
	stack_b = NULL;
	move = get_next_line(0);
	while (move)
	{
		if (check_move(move, &stack_a, &stack_b))
		{	
			clear_lists(&stack_a, &stack_b);
			free(move);
			ft_error(NULL);
		}
		free(move);
		move = get_next_line(0);
	}
	free(move);
	check_output(stack_a, stack_b);
	clear_lists(&stack_a, &stack_b);
	return (0);
}
