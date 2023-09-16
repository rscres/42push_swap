/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:21:23 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/12 16:25:35 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	offset;
	size_t	src_len;

	offset = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= offset)
		return (src_len + size);
	else
		src_len += offset;
	while (*(src + i) != '\0' && (offset + 1) < size)
		*(dest + offset++) = *(src + i++);
	*(dest + offset) = '\0';
	return (src_len);
}
