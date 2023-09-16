/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:17:45 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 19:23:30 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstadd_front(t_dbl_list **lst, t_dbl_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
