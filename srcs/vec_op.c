/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:46:33 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/30 22:06:48 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3 *ft_vec_add(t_vec3 *tar, t_vec3 *u, t_vec3 *v)
{
	tar->x = u->x + v->x;
	tar->y = u->y + v->y;
	tar->z = u->z + v->z;
	return (tar);
}

t_vec3 *ft_vec_sub(t_vec3 *tar, t_vec3 *u, t_vec3 *v)
{
	tar->x = u->x - v->x;
	tar->y = u->y - v->y;
	tar->z = u->z - v->z;
	return (tar);
}

t_vec3 *ft_vec_mul(t_vec3 *tar, t_vec3 *u, t_vec3 *v)
{
	tar->x = u->x * v->x;
	tar->y = u->y * v->y;
	tar->z = u->z * v->z;
	return (tar);
}

t_vec3 *ft_vec_div(t_vec3 *tar, t_vec3 *u, t_vec3 *v)
{
	tar->x = u->x / v->x;
	tar->y = u->y / v->y;
	tar->z = u->z / v->z;
	return (tar);
}

t_vec3 *ft_vec_multi_double(t_vec3 *tar, double t, t_vec3 *v)
{
	tar->x = v->x * t;
	tar->y = v->y * t;
	tar->z = v->z * t;
	return (tar);
}

t_vec3 *ft_vec_div_double(t_vec3 *tar, double t, t_vec3 *v)
{
	tar->x = v->x / t;
	tar->y = v->y / t;
	tar->z = v->z / t;
	return (tar);
}

double ft_vec_dot(t_vec3 *u, t_vec3 *v)
{// 벡터의 내적
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}


t_vec3 *ft_vec_cross(t_vec3 *tar, t_vec3 *u, t_vec3 *v)
{//벡터의 외적
	tar->x = (u->y * v->z) - (u->z * v->y);
	tar->y = (u->z * v->x) - (u->x * v->z);
	tar->z = (u->x * v->y) - (u->y * v->x);
	return (tar);
}

double ft_vec_len_sqrt(t_vec3 *tar)
{
	return (pow(tar->x, 2.0) + pow(tar->y, 2.0) + pow(tar->z, 2.0));
}

double ft_vec_len(t_vec3 *tar)
{//벡터의 크기 구하기 루트 a^2+b^2+c^2
	return(sqrt(ft_vec_len_sqrt(tar)));
}

t_vec3 *ft_vec_unit(t_vec3 *tar, t_vec3 *v)
{//단위 벡터 구하기
	return (ft_vec_div_double(tar, ft_vec_len(v), v));
}

t_vec3 *ft_vec_set_xyz(t_vec3 *tar, double x, double y, double z)
{
	tar->x = x;
	tar->y = y;
	tar->z = z;
	return (tar);
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}