/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:50:28 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/31 17:29:40 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vector.h"

typedef struct	s_ray
{
	t_point3	origin;	//처음 위치
	t_vec3		dir;	//응시하는 방향
}				t_ray;

t_ray		*ft_ray_set(t_ray *tar, t_point3 *origin, t_vec3 *dir);
t_point3	*ft_ray_at(t_point3 *tar, t_ray *ray, double t);

#endif