/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:47:42 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/05 19:19:19 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	int	size_piece;
	int	start;
	int	end;
	int	start_counter;
	int	end_counter;
}	t_data;

//push_swap.c
void	print_list(t_dbl_list *list);
void	print_index(t_dbl_list *list);
int		free_tab(char **tab);

//swap.c
void	swap_a(t_dbl_list **stack_a);
void	swap_b(t_dbl_list **stack_b);
void	swap_all(t_dbl_list **stack_a, t_dbl_list **stack_b);

//rotate.c
void	rotate_a(t_dbl_list **stack_a);
void	rotate_b(t_dbl_list **stack_b);
void	rotate_all(t_dbl_list **stack_a, t_dbl_list **stack_b);

//reverse_rotate.c
void	reverse_rotate_a(t_dbl_list **stack_a);
void	reverse_rotate_b(t_dbl_list **stack_b);
void	reverse_rotate_all(t_dbl_list **stack_a, t_dbl_list **stack_b);

//push.c
void	push_a(t_dbl_list **stack_b, t_dbl_list **stack_a);
void	push_b(t_dbl_list **stack_a, t_dbl_list **stack_b);

//check.c
int		check_sorted(t_dbl_list *stack_a);
int		check_doubles(t_dbl_list *stack_a);
int		check_int(char **arg);
int		input_checker(t_dbl_list **stack_a, int argc, char **argv);

//sort_3.c
void	sort_3elem(t_dbl_list **stack_a);

//sort_5.c
void	sort_5elem(t_dbl_list **stack_a);
int		ft_last_value(t_dbl_list *stack);

//sort_large.c
void	sort_large(t_dbl_list **stack_a);
int		find_max(t_dbl_list *stack);
int		find_min(t_dbl_list *stack);

//error.c
void	ft_error(int n, t_dbl_list **stack_a);

//set_index.c
int		set_index(t_dbl_list **stack_a);
// int		find_min_index(t_dbl_list *stack);

//lst_create.c
int		create_lst_1arg(t_dbl_list **stack_a, char *arr);
int		create_lst_multiarg(t_dbl_list **stack_a, char **argv,
			int argc, int init);

#endif //PUSH_SWAP_H