/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:31:58 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 18:31:39 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	num;
	int				len;

	num = 0;
	len = 0;
	if (n / 10)
		len += ft_putunsigned((n / 10));
	num = n % 10 + '0';
	len += write (1, &num, 1);
	return (len);
}

int	ft_puthex(unsigned int n, int caps)
{
	int	len;

	len = 1;
	if (n / 16)
		len += ft_puthex(n / 16, caps);
	if (caps)
		write (1, &HEX_CAPS[n % 16], 1);
	else
		write (1, &HEX_LOW[n % 16], 1);
	return (len);
}

int	ft_putpointer(unsigned long int n, int flag)
{
	int	len;

	len = 1;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (len = 5);
	}
	if (flag)
	{
		write(1, "0x", 2);
		len += 2;
		flag = 0;
	}
	if (n / 16)
		len += ft_putpointer(n / 16, flag);
	write (1, &HEX_LOW[n % 16], 1);
	return (len);
}

int	ft_putnbr(int n)
{
	int	num;
	int	len;

	num = 0;
	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		len += 2;
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
		len += ft_putnbr((n / 10));
	num = n % 10 + '0';
	len += write (1, &num, 1);
	return (len);
}
