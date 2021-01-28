/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:46:33 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/28 15:11:49 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec *ft_vec_add(t_vec *new, t_vec *u, t_vec *v)
{
	new->x = u->x + v->x;
	new->y = u->y + v->y;
	new->z = u->z + v->z;
	return (new);
}

t_vec *ft_vec_sub(t_vec *new, t_vec *u, t_vec *v)
{
	new->x = u->x - v->x;
	new->y = u->y - v->y;
	new->z = u->z - v->z;
	return (new);
}

t_vec *ft_vec_mul(t_vec *new, t_vec *u, t_vec *v)
{
	new->x = u->x * v->x;
	new->y = u->y * v->y;
	new->z = u->z * v->z;
	return (new);
}

t_vec *ft_vec_div(t_vec *new, t_vec *u, t_vec *v)
{
	new->x = u->x / v->x;
	new->y = u->y / v->y;
	new->z = u->z / v->z;
	return (new);
}

t_vec *ft_vec_multi_double(t_vec *new, double t, t_vec *v)
{
	new->x = v->x * t;
	new->y = v->y * t;
	new->z = v->z * t;
	return (new);
}

t_vec *ft_vec_div_double(t_vec *new, double t, t_vec *v)
{
	new->x = v->x / t;
	new->y = v->y / t;
	new->z = v->z / t;
	return (new);
}

double ft_vec_dot(t_vec *u, t_vec *v)
{// 벡터의 내적
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}


t_vec *ft_vec_cross(t_vec *new, t_vec *u, t_vec *v)
{//벡터의 외적
	new->x = (u->y * v->z) - (u->z * v->y);
	new->y = (u->z * v->x) - (u->x * v->z);
	new->z = (u->x * v->y) - (u->y * v->x);
	return (new);
}

double ft_vec_len_sqrt(t_vec *new)
{
	return (pow(new->x, 2.0) + pow(new->y, 2.0) + pow(new->z, 2.0));
}

double t_vec_len(t_vec *new)
{//벡터의 크기 구하기 루트 a^2+b^2+c^2
	return(sqrt(ft_vec_len_sqrt(new)));
}

t_vec *ft_vec_unit(t_vec *new, t_vec *v)
{//단위 벡터 구하기
	return (ft_vec_div_double(new_vec,ft_vec_len(v), v));
}
