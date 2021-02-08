/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:03:52 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/08 21:10:42 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void ft_parse_plane(char *line)
{
	t_vec3	vec;
	t_vec3	dir_vec;
	int		color[3];
	int		idx;

	idx = 2;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(dir_vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(dir_vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(dir_vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1);
	idx += (ft_atoi(&line[idx], &color[1]) + 1);
	idx += ft_atoi(&line[idx], &color[2]);

	// printf("plane >>> %lf\n", vec.x);
	// printf("plane >>> %lf\n", vec.y);
	// printf("plane >>> %lf\n", vec.z);
	// printf("plane >>> %lf\n", dir_vec.x);
	// printf("plane >>> %lf\n", dir_vec.y);
	// printf("plane >>> %lf\n", dir_vec.z);
	// printf("plane >>> %d\n", color[0]);
	// printf("plane >>> %d\n", color[1]);
	// printf("plane >>> %d\n", color[2]);
}

void ft_parse_sphere(char *line)
{
	t_vec3	center;
	double	dia;
	int		color[3];
	int		idx;

	idx = 2;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(center.x)) + 1);
	idx += (ft_atod(&line[idx], &(center.y)) + 1);
	idx += (ft_atod(&line[idx], &(center.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += ft_atod(&line[idx], &dia);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1);
	idx += (ft_atoi(&line[idx], &color[1]) + 1);
	idx += ft_atoi(&line[idx], &color[2]);

	// printf("sphere >>> %lf\n", center.x);
	// printf("sphere >>> %lf\n", center.y);
	// printf("sphere >>> %lf\n", center.z);
	// printf("sphere >>> %lf\n", dia);
	// printf("sphere >>> %d\n", color[0]);
	// printf("sphere >>> %d\n", color[1]);
	// printf("sphere >>> %d\n", color[2]);
}

void ft_parse_square(char *line)
{
	t_vec3	center;
	t_vec3	dir_vec;
	double	side;
	int		color[3];
	int		idx;

	idx = 2;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(center.x)) + 1);
	idx += (ft_atod(&line[idx], &(center.y)) + 1);
	idx += (ft_atod(&line[idx], &(center.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(dir_vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(dir_vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(dir_vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &side));
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1);
	idx += (ft_atoi(&line[idx], &color[1]) + 1);
	idx += ft_atoi(&line[idx], &color[2]);

	// printf("square >>> %lf\n", center.x);
	// printf("square >>> %lf\n", center.y);
	// printf("square >>> %lf\n", center.z);
	// printf("square >>> %lf\n", dir_vec.x);
	// printf("square >>> %lf\n", dir_vec.y);
	// printf("square >>> %lf\n", dir_vec.z);
	// printf("square >>> %lf\n", side);
	// printf("square >>> %d\n", color[0]);
	// printf("square >>> %d\n", color[1]);
	// printf("square >>> %d\n", color[2]);
}

void ft_parse_cylinder(char *line)
{
	t_vec3	vec;
	t_vec3	dir_vec;
	double	dia;
	double	height;
	int		color[3];
	int		idx;

	idx = 2;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(dir_vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(dir_vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(dir_vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &dia));
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &height));
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1);
	idx += (ft_atoi(&line[idx], &color[1]) + 1);
	idx += ft_atoi(&line[idx], &color[2]);

	// printf("cylinder >>> %lf\n", vec.x);
	// printf("cylinder >>> %lf\n", vec.y);
	// printf("cylinder >>> %lf\n", vec.z);
	// printf("cylinder >>> %lf\n", dir_vec.x);
	// printf("cylinder >>> %lf\n", dir_vec.y);
	// printf("cylinder >>> %lf\n", dir_vec.z);
	// printf("cylinder >>> %d\n", color[0]);
	// printf("cylinder >>> %d\n", color[1]);
	// printf("cylinder >>> %d\n", color[2]);
	// printf("cylinder >>> %lf\n", dia);
	// printf("cylinder >>> %lf\n", height);
}

void ft_parse_triangle(char *line)
{
	t_vec3	vec1;
	t_vec3	vec2;
	t_vec3	vec3;
	int		color[3];
	int		idx;

	idx = 2;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec1.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec1.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec1.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec2.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec2.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec2.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec3.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec3.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec3.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1);
	idx += (ft_atoi(&line[idx], &color[1]) + 1);
	idx += ft_atoi(&line[idx], &color[2]);
}