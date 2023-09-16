/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:05:34 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:17 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{	
	int	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*strwriter(char *str, int len, int minus, int n)
{
	while (len-- > minus)
	{
		if (n % 10 < 0)
			str[len] = -(n % 10) + '0';
		else
			str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		minus;

	minus = 0;
	len = intlen(n);
	if (n < 0)
	{
		len = len + 1;
		minus = 1;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	strwriter(str, len, minus, n);
	return (str);
}
