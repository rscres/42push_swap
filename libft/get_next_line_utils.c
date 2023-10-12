/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:21:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/12 14:19:15 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char	*ft_lstnew_gnl(char content)
{
	t_char			*node;

	node = malloc(sizeof(t_char));
	if (!node)
		return (NULL);
	node->c = content;
	node->next = NULL;
	return (node);
}

int	ft_lstsize_gnl(t_char *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstadd_back_gnl(t_char **lst, t_char *node)
{
	t_char	**current;

	if (!node)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		current = &(*lst)->next;
		while (*current != NULL)
			current = &(*current)->next;
		*current = node;
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	buffer = s;
	if (n == 0)
		return ;
	while (i < n)
	{
		buffer[i] = '\0';
		i++;
	}
}
