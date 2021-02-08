/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:25:46 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/08 21:32:40 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void ft_parse_value(char *line)
{
	if (line[0] == 'R')
		ft_parse_resolution(line);
	else if (line[0] == 'A')
		ft_parse_amb_light(line);
	else if (line[0] == 'c' && line[1] == 'y')
		ft_parse_cylinder(line);
	else if (line[0] == 'c')
		ft_parse_camera(line);
	else if (line[0] == 'l')
		ft_parse_light(line);
	else if (line[0] == 'p' && line[1] == 'l')
		ft_parse_plane(line);
	else if (line[0] == 's' && line[1] == 'p')
		ft_parse_sphere(line);
	else if (line[0] == 's' && line[1] == 'q')
		ft_parse_square(line);
	else if (line[0] == 't' && line[1] == 'r')
		ft_parse_triangle(line);
	else
		printf("[Error] No match .rt files\n");
}

t_scene	*parsing(int fd)
{
	int ret;
	char *line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_parse_value(line);
		printf("line >> %s\n", line);
		free(line);
	}
	printf("line >> %s\n", line);
	free(line);
	return (0);
}