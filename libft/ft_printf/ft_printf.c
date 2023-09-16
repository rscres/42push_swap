/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:16:54 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/15 18:31:31 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		len += write(1, "(null)", 6);
	else
	{
		while (*s)
			len += write(1, s++, 1);
	}
	return (len);
}

int	flag_printer(unsigned int flags, const char c, va_list args)
{
	int	len;

	len = 0;
	if ((flags & HEX_FLAG) && (c == 'x' || c == 'X'))
		len = hashtag_handler(c, args, len);
	if ((flags & PLUS_FLAG) && (c == 'd' || c == 'i'))
		len = plus_handler(args, len);
	else if ((flags & SPACE_FLAG) && (c == 'd'
			|| c == 'i' || c == 's'))
	{
		if (c == 's')
			len += ft_putstr(va_arg(args, char *));
		else if (c == 'd' || c == 'i')
			len = space_handler(args, len);
	}
	return (len);
}

int	flag_handler(const char *str, va_list args, int len, unsigned char flags)
{
	if (!is_placeholder(*(str + 1)))
	{
		len += write(1, "%", 1);
		if (flags & HEX_FLAG)
			len += write(1, "#", 1);
		if (flags & PLUS_FLAG)
			len += write(1, "+", 1);
		else if (flags & SPACE_FLAG)
			len += write(1, " ", 1);
		len += write(1, (str + 1), 1);
		str++;
	}
	else
		len += flag_printer(flags, *(str + 1), args);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				len;
	unsigned char	flags;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		flags = 0;
		if (*str == '%' && is_flag(*(str + 1)))
		{
			while (is_flag(*(str + 1)))
				flags = flag_setter(flags, *((str++) + 1));
			len = flag_handler(str++, args, len, flags);
		}
		else if (*str == '%' && !is_flag(*(str + 1)))
			len = format_checker(len, args, str++);
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
