/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:20 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/11 22:28:29 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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
	else if (move[0] == 10)
		return (0);
	else
		return (1);
	return (0);
}

int	valid_move(char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(move, "sb\n", 3))
		return (1);
	else if (!ft_strncmp(move, "ss\n", 3))
		return (1);
	else if (!ft_strncmp(move, "ra\n", 3))
		return (1);
	else if (!ft_strncmp(move, "rb\n", 3))
		return (1);
	else if (!ft_strncmp(move, "rr\n", 3))
		return (1);
	else if (!ft_strncmp(move, "rra\n", 4))
		return (1);
	else if (!ft_strncmp(move, "rrb\n", 4))
		return (1);
	else if (!ft_strncmp(move, "rrr\n", 4))
		return (1);
	else if (!ft_strncmp(move, "pa\n", 3))
		return (1);
	else if (!ft_strncmp(move, "pb\n", 3))
		return (1);
	else
		return (0);
}

char	**update_moves(char **moves, char *new_move)
{
	static int	size;
	char		**new_arr;
	int			i;

	new_arr = (char **)malloc(sizeof(char *) * (size + 2));
	if (new_arr == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		new_arr[i] = moves[i];
	new_arr[size] = (char *)malloc(ft_strlen(new_move) + 1);
	if (new_arr[size] == NULL)
		return (NULL);
	ft_strlcpy(new_arr[size], new_move, ft_strlen(new_move) + 1);
	new_arr[size + 1] = NULL;
	free(moves);
	moves = new_arr;
	size++;
	return (moves);
}

int	main(int argc, char **argv)
{
	t_dbl_list	*stack_a;
	t_dbl_list	*stack_b;
	char		**moves;
	char		*move;

	stack_a = NULL;
	if (argc < 2)
		exit (1);
	input_checker(&stack_a, argc, argv);
	stack_b = NULL;
	move = get_next_line(0);
	while (move)
	{
		if (move[0] == 10)
			break ;
		if (!valid_move(move) || ft_strlen(move) < 3)
		{
			// free(move);
			// move = get_next_line(0);
			free(move);
			if (moves)
				free_tab(moves);
			ft_error(&stack_a);
		}
		moves = update_moves(moves, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	int i = 0;
	int	size = (int)ft_arrlen(moves);
	while (i < size)
	{
		if (moves[i][0] == 10)
			break ;
		if (check_move(moves[i], &stack_a, &stack_b))
		{
			ft_dbl_lstclear(&stack_b);
			ft_dbl_lstclear(&stack_a);
		}
		i++;
	}
	if (moves)
		free_tab(moves);
	if (check_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (stack_b)
		ft_dbl_lstclear(&stack_b);
	if (stack_a)
		ft_dbl_lstclear(&stack_a);
	return (0);
}
