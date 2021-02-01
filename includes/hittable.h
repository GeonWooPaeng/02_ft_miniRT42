/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:43:15 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 13:54:25 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H
# include "ray.h"
//여러 구체를 생각해야 되서 만들기 되었습니다.
typedef struct	s_hit_rec
{
	t_point3	p;
	t_vec3		normal;
	double		t;
	int			front_face;
}				t_hit_rec;

void			ft_set_face_normal(t_hit_rec *rec, t_ray *r, t_vec3 *outward_normal);

#endif