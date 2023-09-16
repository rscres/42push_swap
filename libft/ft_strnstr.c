/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:01:21 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 16:26:01 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(const char *s1, const char *s2)
{
	while (*s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*temp;

	i = 0;
	temp = (char *)big;
	if (*little == '\0')
		return (temp);
	while (big[i] != '\0' && i + ft_strlen(little) <= len)
	{
		if ((big[i] == little[0]) && cmp(&big[i], little))
			return (&temp[i]);
		i++;
	}
	return (0);
}
