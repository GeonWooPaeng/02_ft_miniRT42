/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:03:27 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 20:46:03 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <math.h>

void	ft_sphere_set(t_sphere *sp, t_point3 *cen, double r)
{
	sp->center = *cen;
	sp->radius = r;
}

int		ft_sphere_hit(t_sphere *sp, t_ray *r, t_t t, t_hit_rec *rec)
{// 구체 교차 부분
	t_vec3 oc;
	t_coef coef;//계수
	double discriminant;//판별
	double sqrtd;
	double root;
	t_vec3 outward_normal;

	ft_vec_sub(&oc, &r->origin, &sp->center);
	coef.a = ft_vec_len_sqrt(&r->dir);
	coef.half_b = ft_vec_dot(&oc, &r->dir);
	coef.c = ft_vec_len_sqrt(&oc) - pow(sp->radius, 2.0);
	discriminant = pow(coef.half_b, 2.0) - coef.a * coef.c;
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	// 허용 간능한 범위에 있는 가장 가까운 근 찾기
	root = (-coef.half_b - sqrtd) / coef.a;
	if (root < t.min || t.max < root)
	{
		root = (-coef.half_b + sqrtd) / coef.a;
		if (root < t.min || t.max < root)
			return (0);
	}
	rec->t = root;
	ft_ray_at(&rec->p, r, rec->t);
	ft_vec_sub(&outward_normal, &rec->p, &sp->center);
	
	// surface를 결정하는 부분
	ft_vec_div_double(&outward_normal, sp->radius, &outward_normal);
	ft_set_face_normal(rec, r, &outward_normal);
	return (1);
}