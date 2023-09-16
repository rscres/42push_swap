/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:16:09 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:51 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*buf_dest;
	char	*buf_src;

	if (n == 0)
		return (dest);
	i = 0;
	buf_dest = (char *)dest;
	buf_src = (char *)src;
	while (i < n)
	{
		*(buf_dest + i) = *(buf_src + i);
		i++;
	}
	return (dest);
}
