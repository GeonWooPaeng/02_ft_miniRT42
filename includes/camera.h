/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:24:04 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/29 16:47:45 by gpaeng           ###   ########.fr       */
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
	double		focal_length;
	t_point3	origin;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		lower_left_corner;
}				t_camera;

void	ft_camera_set(t_camera *cam, double aspect_ratio);
t_ray	*ft_camera_cal_ray(t_ray *tar, t_camera *cam, double u, double v);

#endif