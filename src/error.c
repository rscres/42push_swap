/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:56:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/11 21:10:05 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (i);
}

void	ft_error(t_dbl_list **stack_a)
{
	if (stack_a)
		ft_dbl_lstclear(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
