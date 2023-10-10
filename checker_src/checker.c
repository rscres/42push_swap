/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:20 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 18:41:44 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_dbl_list **stack, int n)
{
	t_dbl_list	*first;
	t_dbl_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	first->prev = NULL;
	second->prev = NULL;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	if (second->next != NULL)
		second->next->prev = second;
	*stack = second;
	if (n == 1)
		write(1, "sa\n", 3);
	else if (n == 2)
		write(1, "sb\n", 3);
}

void	rotate(t_dbl_list **stack, int n)
{
	t_dbl_list	*tmp;
	t_dbl_list	*cur;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	cur = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	tmp->prev = cur;
	tmp->next = NULL;
	cur->next = tmp;
	if (n == 1)
		write(1, "ra\n", 3);
	else if (n == 2)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_dbl_list **stack, int n)
{
	t_dbl_list	*tmp;
	t_dbl_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	tmp = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	head->prev = tmp;
	*stack = tmp;
	if (n == 1)
		write(1, "rra\n", 4);
	else if (n == 2)
		write(1, "rrb\n", 4);
}

void	push(t_dbl_list **stack_src, t_dbl_list **stack_dest, int n)
{
	t_dbl_list	*tmp;

	if (!stack_src)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	tmp->next = *stack_dest;
	if (*stack_dest)
		(*stack_dest)->prev = tmp;
	*stack_dest = tmp;
	if (n == 1)
		write(1, "pa\n", 3);
	else if (n == 2)
		write(1, "pb\n", 3);
}

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
