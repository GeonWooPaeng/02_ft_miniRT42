/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:59:01 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 14:03:07 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPHERE_H
# define	SPHERE_H
# include	"hittable.h"
# include 	"vector.h"

typedef struct	s_sphere
{
	t_point3	center;
	double		radius;
}				t_sphere;

typedef struct	s_coef
{
	double		a;
	double		half_b;
	double		c;
}				t_coef;

typedef struct	s_t
{
	double		min;
	double		max;
}				t_t;

void			ft_sphere_set(t_sphere *sp, t_point3 *cen, double r);
int				ft_sphere_hit(t_sphere *sp, t_ray *r, t_t t, t_hit_rec *rec);

#endif