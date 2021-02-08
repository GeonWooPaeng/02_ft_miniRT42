/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:23:14 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/08 21:23:42 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	SCENE_H
# define SCENE_H

typedef struct		s_scene
{
	void			*mlx;
	int				width;
	int				height;
	double			aspect_ratio;
}					t_scene;

#endif