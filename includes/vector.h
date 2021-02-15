/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:41:01 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/14 23:16:34 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <math.h>
#include <stdlib.h>

typedef struct	s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

t_vec3 *ft_vec_add(t_vec3 *tar, t_vec3 *u, t_vec3 *v);
t_vec3 *ft_vec_sub(t_vec3 *tar, t_vec3 *u, t_vec3 *v);
t_vec3 *ft_vec_mul(t_vec3 *tar, t_vec3 *u, t_vec3 *v);
t_vec3 *ft_vec_div(t_vec3 *tar, t_vec3 *u, t_vec3 *v);
t_vec3 *ft_vec_multi_double(t_vec3 *tar, double t, t_vec3 *v);
t_vec3 *ft_vec_div_double(t_vec3 *tar, double t, t_vec3 *v);
t_vec3 *ft_vec_cross(t_vec3 *tar, t_vec3 *u, t_vec3 *v);
t_vec3 *ft_vec_unit(t_vec3 *tar, t_vec3 *v);
t_vec3 *ft_vec_set_xyz(double x, double y, double z);
double ft_vec_dot(t_vec3 *u, t_vec3 *v);
double ft_vec_len_sqrt(t_vec3 *tar);
double ft_vec_len(t_vec3 *tar);
int create_trgb(int t, int r, int g, int b);
t_vec3 *ft_vec_reflect(t_vec3 *refl, t_vec3 *v, t_vec3 *u);

typedef t_vec3 t_point3;
typedef t_vec3 t_color;

#endif