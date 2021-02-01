/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:42:47 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 19:57:52 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

void	ft_set_face_normal(t_hit_rec *rec, t_ray *r, t_vec3 *outward_normal)
{
// ray와 normal face(법사면)이 같은 방향이면 ray는 물체 내부에 있고 
// ray와 normal face이 반대 방향이면 ray는 물체 외부에 있습니다.
// => 두 벡터의 내적으로 결정됩니다.(양수: ray는 구 내부)
	if (ft_vec_dot(&r->dir, outward_normal) < 0)
		rec->front_face = 1; // ray가 구 외부에 있다
	else
		rec->front_face = 0;
	//normal이 항상 표면에서 outward를 가리키거나 항상 incident ray(입사 광선)을 가리키도록 설정할 수 있다.
	if (rec->front_face == 1)
		rec->normal = *outward_normal; 
	else
		ft_vec_multi_double(&rec->normal, -1, outward_normal);
	
}