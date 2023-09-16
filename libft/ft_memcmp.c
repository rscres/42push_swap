/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:09:17 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 21:31:37 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = (const unsigned char *)ptr1;
	p2 = (const unsigned char *)ptr2;
	while (i < num)
	{
		if (*(p1 + i) != *(p2 + i))
		{
			if (*(p1 + i) > *(p2 + i))
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
