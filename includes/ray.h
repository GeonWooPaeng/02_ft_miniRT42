/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:50:28 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/28 14:53:03 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vector.h"

typedef t_vec t_point;
typedef t_vec t_color;

typedef struct	s_ray
{
	t_point		orig;	//처음 위치
	t_vec		dir;	//응시하는 방향
}				t_ray;

#endif