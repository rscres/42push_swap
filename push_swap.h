/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:47:42 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/25 20:39:37 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

//Movement
void	print_list(t_dbl_list *list);

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

//sort_3.c
void	algo_3arg(t_dbl_list **stack_a);

//sort_5.c
void	algo_5elem(t_dbl_list **stack_a);

//sort_large.c
void	algo_large(t_dbl_list **stack_a);
int		find_max(t_dbl_list *stack);
int		find_min(t_dbl_list *stack);

//error.c
void	ft_error(int n);

#endif //PUSH_SWAP_H