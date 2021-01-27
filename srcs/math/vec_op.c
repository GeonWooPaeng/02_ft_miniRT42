/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:46:33 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/27 16:44:13 by gpaeng           ###   ########.fr       */
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

double ft_vec_dot(t_vec *u, t_vec *v)
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}


t_vec *ft_vec_cross(t_vec *new, t_vec *u, t_vec *v)
{
    new->x = (u->y * v->z) - (u->z * v->y);
    new->y = (u->z * v->x) - (u->x * v->z);
    new->z = (u->x * v->y) - (u->y * v->x);
    return (new);
}
