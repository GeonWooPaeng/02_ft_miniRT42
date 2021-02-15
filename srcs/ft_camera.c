/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:27:54 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/14 23:17:06 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_camera.h"

// t_camera	*ft_camera_set(t_camera *target)
// {//카메라 초기값 지정함수
// 	double aspect_ratio;
// 	double viewport_height;
// 	double viewport_width;
// 	double focal_length;

// 	aspect_ratio = 16.0 / 9.0;
// 	viewport_height = 2.0;
// 	viewport_width = aspect_ratio * viewport_height;
// 	focal_length = 1.0;
// 	ft_vec_set_xyz(&target->origin, 0, 0, 0);
// 	ft_vec_set_xyz(&target->horizontal, viewport_width, 0.0, 0.0);
// 	ft_vec_set_xyz(&target->vertical, 0.0, viewport_height, 0.0);
// 	target->lower_left_corner.x = target->origin.x - target->horizontal.x / 2 - target->vertical.x / 2 - 0;
// 	target->lower_left_corner.y = target->origin.y - target->horizontal.y / 2 - target->vertical.y / 2 - 0;
// 	target->lower_left_corner.z = target->origin.z - target->horizontal.z / 2 - target->vertical.z / 2 - focal_length;
// 	return (target);
// }

t_camera	*ft_camera_set(t_vec3 *pos, t_vec3 *rot, int fov)
{
	t_camera	*camera;

	camera->origin = pos;
	camera->rotation = rot;
	camera->fov = fov;
	return (camera);
}

t_camera	*ft_camera_cpy(t_camera *cam)
{
	t_vec3		*pos;
	t_vec3		*rot;

	pos = ft_vec_set_xyz(cam->origin->x, cam->origin->y, cam->origin->z);
	rot = ft_vec_set_xyz(cam->rotation->x, cam->rotation->y, cam->rotation->z);
	return (ft_camera_set(pos, rot, cam->fov));
}

// t_ray	*ft_camera_get_ray(t_ray *tar, t_camera *cam, double u, double v)
// {// lower_left_corner를 기준으로 매개변수 u,v의 값의 비율로 
// //스크린 상의 해당 지점까지의 광선을 구한다.
// 	t_vec3 tmp;

// 	tmp.x = cam->lower_left_corner.x 
// 				+ u * cam->horizontal.x
// 				+ v * cam->vertical.x
// 				- cam->origin.x;
// 	tmp.y = cam->lower_left_corner.y
// 				+ u * cam->horizontal.y
// 				+ v * cam->vertical.y
// 				- cam->origin.y;
// 	tmp.z = cam->lower_left_corner.z
// 				+ u * cam->horizontal.z
// 				+ v * cam->vertical.z
// 				- cam->origin.z;
// 	return (ft_ray_set(tar, &(cam->origin), &tmp));
// }