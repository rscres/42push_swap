/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:56:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/10 13:03:02 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_dbl_list **stack_a)
{
	if (stack_a)
		ft_dbl_lstclear(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
