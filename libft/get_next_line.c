/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/10/12 14:20:47 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*line_writer(t_char **lst)
{
	t_char	*line;
	t_char	*temp;
	char	*line_ret;
	int		i;

	line_ret = malloc((ft_lstsize_gnl(*lst) + 1) * sizeof(char));
	if (!line_ret)
		return (NULL);
	line = *lst;
	i = 0;
	while (line != NULL)
	{
		line_ret[i++] = line->c;
		temp = line;
		line = line->next;
		free(temp);
	}
	line_ret[i] = '\0';
	*lst = NULL;
	return (line_ret);
}

static char	*line_reader(t_gnl *data, t_char *head, int fd)
{
	while (data->bytesread > 0)
	{
		ft_lstadd_back_gnl(&head, ft_lstnew_gnl(data->str[data->pos]));
		if (data->str[data->pos] == '\n' || data->str[data->pos] == '\0')
			break ;
		if (data->pos == data->bytesread - 1 || data->bytesread == 1)
		{
			data->pos = -1;
			ft_bzero(data->str, BUFFER_SIZE);
			if (read(fd, data->str, BUFFER_SIZE) <= 0)
				break ;
		}
		data->pos++;
	}
	data->pos++;
	return (line_writer(&head));
}

char	*get_next_line(int fd)
{
	t_char			*head;
	static t_gnl	data;

	if (data.pos >= data.bytesread || data.pos == 0)
	{
		data.pos = 0;
		data.bytesread = read(fd, data.str, BUFFER_SIZE);
	}
	if (data.bytesread <= 0 || data.str[data.pos] == '\0')
		return (NULL);
	head = NULL;
	return (line_reader(&data, head, fd));
}
