/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:24:04 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/14 20:19:49 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"
#include "ray.h"

typedef struct	s_camera
{
	t_vec3		*origin;
	t_vec3		*rotation;
	int			fov;
}				t_camera;

t_camera	*ft_camera_set(t_vec3 *pos, t_vec3 *rot, int fov);
t_ray	*ft_camera_get_ray(t_ray *tar, t_camera *cam, double u, double v);

#endif