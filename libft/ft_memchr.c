/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:21:27 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:43 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (buffer[i] == (unsigned char )c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
