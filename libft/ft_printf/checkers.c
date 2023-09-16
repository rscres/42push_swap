/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:08:11 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 18:31:26 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	format_checker(int len, va_list args, const char *str)
{
	if (*(str + 1) == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*(str + 1) == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*(str + 1) == 'p')
		len += ft_putpointer(va_arg(args, unsigned long int), 1);
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (*(str + 1) == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*(str + 1) == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*(str + 1) == '%')
		len += write(1, "%", 1);
	return (len);
}

int	is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '+')
		return (1);
	return (0);
}

int	flag_setter(unsigned char flags, char c)
{
	if (c == '#')
		flags |= HEX_FLAG;
	else if (c == '+')
	{
		flags |= PLUS_FLAG;
		flags &= ~(SPACE_FLAG);
	}
	else if (c == ' ' && (flags & PLUS_FLAG) == 0)
		flags |= SPACE_FLAG;
	return (flags);
}

int	is_placeholder(char c)
{
	if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'x' || c == 'X'
		|| c == 'u' || c == 'p')
		return (1);
	return (0);
}
