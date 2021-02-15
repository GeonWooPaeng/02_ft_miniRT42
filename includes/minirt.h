/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:41:36 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/14 17:06:56 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "utils.h"
# include "vector.h"
# include "ray.h"
# include "hittable_list.h"
# include "sphere.h"
# include "ft_random.h"
# include "ft_camera.h"
# include "parsing.h"

typedef struct	s_mlx
{
	t_scene		*scene;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx;

#endif