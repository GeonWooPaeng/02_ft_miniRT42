/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:04:00 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/08 21:10:30 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void ft_parse_resolution(char *line)
{
	int xrender;
	int yrender;
	int idx;

	xrender = 0;
	yrender = 0;
	idx = 1;
	idx += ft_isspace(&line[idx]);
	idx += ft_atoi(&line[idx], &xrender);
	idx += ft_isspace(&line[idx]);
	idx += ft_atoi(&line[idx], &yrender);
	// printf("xrender >> %d\n", xrender);
	// printf("yrender >> %d\n", yrender);

}

void ft_parse_amb_light(char *line)
{
	double ill_ratio; //조도 비율
	int color[3];
	int idx;

	idx = 1;
	idx += ft_isspace(&line[idx]);
	idx += ft_atod(&line[idx], &ill_ratio);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1); //R
	idx += (ft_atoi(&line[idx], &color[1]) + 1); //G
	idx += ft_atoi(&line[idx], &color[2]); //B
	// printf("color >> %d\n", color[0]);
	// printf("color >> %d\n", color[1]);
	// printf("color >> %d\n", color[2]);
	// printf("ill >> %lf\n", ill_ratio);
}

void ft_parse_camera(char *line)
{
	double	loc[3];
	t_vec3	vec;
	int		fov;
	int		idx;
	
	idx = 1;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &loc[0]) + 1);
	idx += (ft_atod(&line[idx], &loc[1]) + 1);
	idx += (ft_atod(&line[idx], &loc[2]) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += ft_atoi(&line[idx], &fov);
	// printf("camera >>> %lf\n", loc[0]);
	// printf("camera >>> %lf\n", loc[1]);
	// printf("camera >>> %lf\n", loc[2]);
	// printf("camera >>> %lf\n", vec.x);
	// printf("camera >>> %lf\n", vec.y);
	// printf("camera >>> %lf\n", vec.z);
	// printf("camera >>> %d\n", fov);
}

void ft_parse_light(char *line)
{
	int		idx;
	int		color[3];
	t_vec3	vec;
	double	light_ratio;

	idx = 1;
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &(vec.x)) + 1);
	idx += (ft_atod(&line[idx], &(vec.y)) + 1);
	idx += (ft_atod(&line[idx], &(vec.z)) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atod(&line[idx], &light_ratio) + 1);
	idx += ft_isspace(&line[idx]);
	idx += (ft_atoi(&line[idx], &color[0]) + 1);
	idx += (ft_atoi(&line[idx], &color[1]) + 1);
	idx += ft_atoi(&line[idx], &color[2]);
	
	// printf("light >>> %lf\n", vec.x);
	// printf("light >>> %lf\n", vec.y);
	// printf("light >>> %lf\n", vec.z);
	// printf("light >>> %d\n", color[0]);
	// printf("light >>> %d\n", color[1]);
	// printf("light >>> %d\n", color[2]);
	// printf("light >>> %lf\n", light_ratio);
}