/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:24:04 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/04 15:01:00 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"
#include "ray.h"

typedef struct	s_camera
{
	double		view_height;
	double		view_width;
	double		focal_length; //초점길이, 클수록 크게 보인다.
	t_point3	origin;
	t_vec3		horizontal; //수평선
	t_vec3		vertical; //수직선
	t_vec3		lower_left_corner;
}				t_camera;

t_camera	*ft_camera_set(t_camera *target);
t_ray	*ft_camera_get_ray(t_ray *tar, t_camera *cam, double u, double v);

#endif