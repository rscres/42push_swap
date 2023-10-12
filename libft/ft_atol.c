/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:47:26 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/12 13:46:49 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

long int	ft_atol(const char *str)
{
	long int	num;
	int			minus;

	num = 0;
	minus = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	if (minus == -1 && !ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	if (minus == -1)
		num = -num;
	return (num);
}
