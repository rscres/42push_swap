/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:08:41 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/21 12:42:47 by rseelaen         ###   ########.fr       */
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
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
