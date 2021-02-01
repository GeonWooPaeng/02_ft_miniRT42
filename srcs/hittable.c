/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:42:47 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 13:55:54 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

void	ft_set_face_normal(t_hit_rec *rec, t_ray *r, t_vec3 *outward_normal)
{//광선을 받는 함수
	if (ft_vec_dot(&r->dir, outward_normal) < 0)
		rec->front_face = 1;
	else
		rec->front_face = 0;
	if (rec->front_face == 1)
		rec->normal = *outward_normal;
	else
		ft_vec_multi_double(&rec->normal, -1, outward_normal);
	
}