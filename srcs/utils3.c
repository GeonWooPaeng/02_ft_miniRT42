/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:09:15 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/08 16:53:34 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


int	ft_atoi(char *str, int *n)
{
	int sign;
	int idx;
	long num;

	num = 0;
	sign = 1;
	idx = 0;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	*n = sign * num;
	return (idx);
}

int ft_atod(char *str, double *n)
{
	double point; //자리수
	int num;
	int idx;

	idx = ft_atoi(str, &num);
	point = (num < 0 || (num == 0 && idx == 2)) ? -0.1 : 0.1;
	if (str[idx] == '.')
		idx++;
	*n = num;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		*n += point * (str[idx] - '0');
		point *= 0.1;
		idx++;
	}
	return (idx);
}