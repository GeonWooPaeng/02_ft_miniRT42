/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:26:39 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 21:02:40 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_H
# define FT_RANDOM_H
# define FT_RAND_MAX 65535

unsigned int	ft_rand(void);
double			ft_random_double(void);
double			ft_random_double_range(double min, double max);
double			ft_clamp(double x, double min, double max);

#endif