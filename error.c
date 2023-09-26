/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:56:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/26 12:54:43 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int n, t_dbl_list **stack_a)
{
	if (stack_a)
		ft_dbl_lstclear(stack_a);
	ft_putstr_fd("Error\n", 2);
	// if (n == 0)
	// 	ft_printf("Error\n");
	// else if (n == 1)
	// 	ft_printf("Error: not enough arguments\n");
	// else if (n == 2)
	// 	ft_printf("Error: invalid input. Please input only numbers\n");
	// else if (n == 3)
	// 	ft_printf("Error: duplicate numbers\n");
	exit(EXIT_FAILURE);
}
