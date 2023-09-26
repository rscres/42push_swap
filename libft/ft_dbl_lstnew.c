/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:08:41 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/25 19:40:07 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstnew(int content)
{
	t_dbl_list	*node;

	node = malloc(sizeof(t_dbl_list));
	if (!node)
		return (NULL);
	node->value = content;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
