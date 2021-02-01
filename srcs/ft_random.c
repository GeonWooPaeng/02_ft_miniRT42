/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:03:04 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 21:07:13 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_random.h"

unsigned short	g_lfsr = 0xACE1u;
unsigned int	g_bit;

unsigned int	ft_rand(void)
{
	g_bit = ((g_lfsr >> 0) ^ (g_lfsr >> 2) ^ (g_lfsr >> 3) ^ (g_lfsr >> 5));
	return (g_lfsr = (g_lfsr >> 1) | (g_bit << 15));
}

double			ft_random_double(void)
{
	return (ft_rand() / (FT_RAND_MAX + 1.0));
}

double			ft_random_double_range(double min, double max)
{
	return (min + (max - min) * ft_random_double());
}

double			ft_clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}