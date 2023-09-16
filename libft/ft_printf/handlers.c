/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:30:28 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 18:31:35 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	plus_handler(va_list args, int len)
{
	int	num;

	num = va_arg(args, int);
	if (num < 0)
		len += ft_putnbr(num);
	else
	{
		len += write(1, "+", 1);
		len += ft_putnbr(num);
	}
	return (len);
}

int	space_handler(va_list args, int len)
{
	int	num;

	num = va_arg(args, int);
	if (num < 0)
		len += ft_putnbr(num);
	else
	{
		len += write(1, " ", 1);
		len += ft_putnbr(num);
	}
	return (len);
}

int	hashtag_handler(const char c, va_list args, int len)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (c == 'X')
	{
		len += write(1, "0X", 2);
		len += ft_puthex(num, 1);
	}
	else if (c == 'x')
	{
		len += write(1, "0x", 2);
		len += ft_puthex(num, 0);
	}
	return (len);
}
