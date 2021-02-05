/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:40:23 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/05 13:12:44 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_make_line(char **arr, int *check)
{
	char *new_lineptr;
	char *backup;
	char *tmp;

	new_lineptr = ft_strchr(*arr, '\n');
	if (new_lineptr)
	{
		*check = 1;
		backup = ft_strndup(*arr, new_lineptr - *arr);
		tmp = ft_strndup(new_lineptr + 1, ft_strlen(new_lineptr + 1));
		free(*arr);
		*arr = tmp;
		return (backup);
	}
	else
	{
		*check = 0;
		return (*arr);
	}
}

int		ft_make_arr(char **arr, char *buf, ssize_t nr)
{
	char *backup;

	if (*arr == NULL)
	{
		backup = ft_strndup(buf, nr);
	}
	else
	{
		backup = ft_strjoin(*arr, buf);
		free(*arr);
	}
	*arr = backup;
	if (ft_strchr(*arr, '\n'))
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *arr[256];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		nr;
	int			check;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || fd >= 256)
		return (-1);
	while ((nr = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[nr] = '\0';
		if (ft_make_arr(&arr[fd], buf, nr) || nr == 0)
			break ;
	}
	if (nr < 0)
		return (-1);
	*line = ft_make_line(&arr[fd], &check);
	if (!check)
	{
		arr[fd] = 0;
		return (0);
	}
	return (1);
}