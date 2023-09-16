/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:09:58 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 19:19:08 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	**current;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = &(*lst)->next;
		while (*current != NULL)
			current = &(*current)->next;
		*current = new;
	}
}
