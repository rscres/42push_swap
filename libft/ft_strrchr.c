/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:43:54 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 21:33:06 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	if (!ft_isascii(c))
		return ((char *)str);
	i = ft_strlen((char *)str);
	while (i > 0)
	{
		if (*(str + i - 1) == c)
			return ((char *)(str + i - 1));
		i--;
	}
	return (NULL);
}
