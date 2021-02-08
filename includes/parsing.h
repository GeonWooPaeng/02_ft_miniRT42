/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:08:28 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/08 21:33:35 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "vector.h"
#include "scene.h"

void ft_parse_resolution(char *line);
void ft_parse_amb_light(char *line);
void ft_parse_camera(char *line);
void ft_parse_light(char *line);

void ft_parse_plane(char *line);
void ft_parse_sphere(char *line);
void ft_parse_square(char *line);
void ft_parse_cylinder(char *line);
void ft_parse_triangle(char *line);

void ft_parse_value(char *line);
t_scene	*parsing(int fd);

#endif