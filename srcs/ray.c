/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:19:21 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/29 16:34:02 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray		*ft_ray_set(t_ray *tar, t_point3 *origin, t_vec3 *dir)
{
	tar->origin = *origin;
	tar->dir = *dir;
	return (tar);
}

t_point3	*ft_ray_point(t_point3 *tar, t_ray *ray, double t)
{
	tar->x = ray->origin.x + t * ray->dir.x;
	tar->y = ray->origin.y + t * ray->dir.y;
	tar->z = ray->origin.z + t * ray->dir.z;
	return (tar);
}