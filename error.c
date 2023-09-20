/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:56:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/20 17:00:14 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int n)
{
	if (n == 0)
		ft_printf("Error\n");
	else if (n == 1)
		ft_printf("Error: not enough arguments\n");
	else if (n == 2)
		ft_printf("Error: invalid input. Please input only numbers\n");
	else if (n == 3)
		ft_printf("Error: duplicate numbers\n");
	exit(EXIT_FAILURE);
}
