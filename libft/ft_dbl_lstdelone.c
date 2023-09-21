/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstdelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:30:06 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/21 12:44:37 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstdelone(t_dbl_list *lst, void (*del)(int))
{
	t_dbl_list	*next;
	t_dbl_list	*prev;

	if (!lst)
		return ;
	next = lst->next;
	prev = lst->prev;
	del(lst->value);
	free(lst);
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
}
